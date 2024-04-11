#include<stdio.h>
#include<cstring>
#include<algorithm>
#define rep(i,j,k) for(int i=(int)j;i<=(int)k;i++)
#define per(i,j,k) for(int i=(int)j;i>=(int)k;i--)
using namespace std;
const int N=210000;
int p[N];int n;
int du[N];
int q[N];
bool vis[N];
int main(){
	scanf("%d",&n);
	rep(i,1,n)scanf("%d",&p[i]);
	int rt=0;
	rep(i,1,n)du[p[i]]++;
	rep(i,1,n)if(!du[i]){
		du[i]=-1;q[++q[0]]=i;
	}
	rep(i,1,q[0]){
		int x=q[i];
		du[p[x]]--;
		if(du[p[x]]==0)q[++q[0]]=p[x];
	}
	rep(i,1,n)if(i==p[i])rt=i;
	int ans=0;
	if(!rt)rep(i,1,n)if(du[i]>0){
		rt=i;
		int x=i;
		vis[x]=1;
		for(x=p[x];!vis[x];x=p[x])vis[x]=1;
		p[rt]=rt;
		++ans;
		break;
	}
	
	rep(i,1,n)if(du[i]>0)if(!vis[i]){
		vis[i]=1;
		if(p[i]==rt)continue;
		for(int x=p[i];!vis[x];x=p[x])vis[x]=1;
		p[i]=rt;
		++ans;
	}
	printf("%d\n",ans);
	rep(i,1,n)printf("%d ",p[i]);
	return 0;
}