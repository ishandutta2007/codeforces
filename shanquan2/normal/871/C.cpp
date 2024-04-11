#include<bits/stdc++.h>
#define M 1000000007
using namespace std;

struct edge{
	int nxt,to;
}e[200005];
int n,ft[200005],d[200005],x[100005],y[100005],px[100005],py[100005],nx,ny,cnt=1,a,b,ans=1;
bool v[200005];
void dfs(int x){
	v[x]=1;a++;b+=d[x];
	for(int i=ft[x];i;i=e[i].nxt)if(!v[e[i].to])dfs(e[i].to);
}
int main(){
	scanf("%d",&n);
	for(int i=0;i<n;i++){
		scanf("%d%d",&x[i],&y[i]);
		px[i]=x[i],py[i]=y[i];
	}
	sort(px,px+n);nx=unique(px,px+n)-px;
	sort(py,py+n);ny=unique(py,py+n)-py;
	for(int i=0;i<n;i++){
		x[i]=lower_bound(px,px+nx,x[i])-px;
		y[i]=lower_bound(py,py+ny,y[i])-py;
		e[cnt]=(edge){ft[x[i]],y[i]+n};ft[x[i]]=cnt++;d[x[i]]++;
		e[cnt]=(edge){ft[y[i]+n],x[i]};ft[y[i]+n]=cnt++;d[y[i]+n]++;
	}
	for(int i=0;i<n;i++)if(!v[i]){
		a=0,b=0;
		dfs(i);b/=2;
		int t=1;for(int i=0;i<a;i++)t=(t+t)%M;
		if(b==a-1)t--;
		ans=1ll*ans*t%M;
	}
	printf("%d\n",ans);
	return 0;
}