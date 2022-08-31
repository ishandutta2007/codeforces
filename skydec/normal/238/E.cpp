#include<cstring>
#include<cstdlib>
#include<cstdio>
#include<cmath>
#include<algorithm>
#include<map>
#include<set>
#include<vector>
#define pb push_back
#define rep(i,j,k) for(int i=(j);i<=(int)k;i++)
#define per(i,j,k) for(int i=(j);i>=(int)k;i--)
#define lowbit(x) ((x)&(-(x)))
#define fi first
#define se second
#define pii pair<int,int>
using namespace std;
typedef long long LL;
typedef double db;
typedef set<int>::iterator it;
const int N=105;
int f[N][N],ans[N],rp[N],S,T,s[N],t[N],n,m,k,vis[N],cho;
int must[N][N];
int ct[N][N];
int dfs(int x,int y){
	if(vis[x]==cho)return rp[x];vis[x]=cho;int res=-1;
	rep(j,1,n)if(f[x][j]==1&&f[x][j]+f[j][y]==f[x][y])res=max(res,dfs(j,y));
	if(res<0)res=ans[0];
	rp[x]=min(ans[x]+1,res);
	return rp[x];
}
int main(){
	scanf("%d%d%d%d",&n,&m,&S,&T);
	memset(f,63,sizeof f);
	memset(ans,63,sizeof ans);
	rep(i,1,n)f[i][i]=0;
	rep(i,1,m){
		int x,y;scanf("%d%d",&x,&y);
		f[x][y]=1;
	}
	rep(p,1,n)rep(i,1,n)rep(j,1,n)f[i][j]=min(f[i][p]+f[p][j],f[i][j]);
	scanf("%d",&k);
	rep(i,1,k){
		scanf("%d%d",&s[i],&t[i]);
		rep(j,1,n)if(f[s[i]][j]<1e9&&f[s[i]][j]+f[j][t[i]]==f[s[i]][t[i]])ct[i][f[s[i]][j]]++;
		rep(j,1,n)if(f[s[i]][j]<1e9&&f[s[i]][j]+f[j][t[i]]==f[s[i]][t[i]]&&ct[i][f[s[i]][j]]==1)must[i][j]=1;
		//printf("___");rep(j,1,n)printf("%d ",f[s[i]][j]);printf("\n");
	}
	bool is_jabby_god=1;
	ans[T]=0;
	while(is_jabby_god){
		bool flag=0;
		rep(i,1,k)rep(j,1,n)if(must[i][j]){
			++cho;int tmp=dfs(j,t[i]);if(tmp<ans[j]){ans[j]=tmp;flag=1;}
		}
		if(!flag)break;
	}
	if(ans[S]<1e9)printf("%d\n",ans[S]);
	else printf("-1\n");
	return 0;
}