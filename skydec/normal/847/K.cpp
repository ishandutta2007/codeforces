#include<bits/stdc++.h>
#define pii pair<int,int>
#define fi first
#define se second
#define rep(i,j,k) for(int i=(int)j;i<=(int)k;i++)
#define per(i,j,k) for(int i=(int)j;i>=(int)k;i--)
using namespace std;
typedef long long LL;
const int N=605;
int Q,a,b,k,f,n;
map<string,int> id;
char str[25];
int cost[N][N];
int q[N*N];
int main(){
	scanf("%d%d%d%d%d",&Q,&a,&b,&k,&f);
	int ans=0;
	int pa,pb;pa=pb=0;
	rep(i,1,Q){
		int x,y;
		scanf("%s",str+1);
		if(!id[str+1])id[str+1]=++n;
		x=id[str+1];
		scanf("%s",str+1);
		if(!id[str+1])id[str+1]=++n;
		y=id[str+1];
		
		int ww=a;
		if(i!=1&&pb==x)ww=b;
		cost[min(x,y)][max(x,y)]+=ww;
		ans+=ww;
		pa=x;
		pb=y;
	}
	rep(i,1,n)rep(j,i+1,n)if(f<cost[i][j])q[++q[0]]=cost[i][j]-f;
	sort(q+1,q+1+q[0]);
	reverse(q+1,q+1+q[0]);
	rep(i,1,min(q[0],k))ans-=q[i];
	printf("%d\n",ans);
	return 0;
}