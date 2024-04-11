#include<stdio.h>
#include<cstring>
#include<algorithm>
#include<vector>
#include<map>
#include<assert.h>
#include<set>
#include<cmath>
#include<queue>
#include<cstdlib>
#include<iostream>
#include<bitset>
#define pii pair<int,int>
#define fi first
#define se second
#define pb push_back
#define rep(i,j,k) for(int i=(int)(j);i<=(int)(k);i++)
#define per(i,j,k) for(int i=(int)(j);i>=(int)(k);i--)
using namespace std;
typedef long long LL;
typedef double db;
const int N=100005;
const int P=1000000007;
inline int Pow(int a,int b){
	int c=1;
	for(;b;b>>=1,a=a*1ll*a%P)if(b&1)c=c*1ll*a%P;
	return c;
}
int n,k;
vector<int>go[N];
int res[205];
bool vis[N],inq[N];int q[N],fa[N],sz[N];
int gr(int S){
	q[q[0]=1]=S;inq[S]=1;

	rep(i,1,q[0]){
		int x=q[i];
		for(int y:go[x])if(!vis[y])if(!inq[y]){
			inq[y]=1;q[++q[0]]=y;fa[y]=x;
		}
	}
	int rt=0;
	int ma1=1e9;
	per(i,q[0],1){
		int x=q[i];sz[x]=1;
		int bg=0;
		for(int y:go[x])if(inq[y]&&(!vis[y]))if(fa[y]==x){
			sz[x]+=sz[y];
			bg=max(bg,sz[y]);
		}
		bg=max(bg,q[0]-sz[x]);
		if(bg<ma1){
			ma1=bg;
			rt=x;
		}
	}
	rep(i,1,q[0]){
		int x=q[i];
		sz[x]=fa[x]=0;inq[x]=0;
	}
	return rt;
}
int dfn[N],ed[N],dftot,id[N];
void dfs(int x){
	dfn[x]=++dftot;id[dftot]=x;sz[x]=1;
	for(int y:go[x])if(fa[y]==x&&inq[y]&&(!vis[y])){
		dfs(y);sz[x]+=sz[y];
	}
	ed[x]=dftot;
}
int dp[N][205];
int bt[205];
int po=0;
void work(int S){
	q[q[0]=1]=S;inq[S]=1;
	rep(i,1,q[0]){
		int x=q[i];
		for(int y:go[x])if(!vis[y])if(!inq[y]){
			inq[y]=1;q[++q[0]]=y;fa[y]=x;
		}
	}
	//if(q[0]==1)return;
	//po+=q[0];
	dftot=0;
	dfs(S);

	rep(i,1,dftot+1)rep(j,0,k)dp[i][j]=0;

	dp[2][0]=2;
	rep(j,0,k)bt[j]=res[j];
	rep(i,2,dftot){
		int bb=ed[id[i]]+1;

		//choose but last
		int up=min(i+1,k);
		rep(j,0,up)if(dp[i][j]){
			register int w=dp[i][j];
			if(sz[id[i]]!=1)w=(P-w);
			register int w2=(w+dp[i][j])%P;
			dp[bb][j]=(dp[bb][j]+w2)%P;
			dp[bb][j+1]=(dp[bb][j+1]+w)%P;
			if(sz[id[i]]!=1){
				int t=dp[i][j]*2%P;
				dp[i+1][j]=(dp[i+1][j]+t)%P;
				dp[i+1][j+1]=(dp[i+1][j+1]+t)%P;
			}
		}
	}
	rep(i,0,k)res[i]=(res[i]+dp[dftot+1][i])%P;
	for(int y:go[S])if(fa[y]==S&&(!vis[y])&&(inq[y])){
		int l=dfn[y];
		int r=ed[y];
		rep(i,l,r+1)rep(j,0,k)dp[i][j]=0;
		dp[l][0]=1;
		{
			int i=l;
			int bb=ed[id[i]]+1;
			int up=min(i-l+1,k);
			rep(j,0,up)if(dp[i][j]){
				register int w=dp[i][j];
				if(sz[id[i]]!=1)w=(P-w);
				register int w2=(w+dp[i][j])%P;
				dp[bb][j]=(dp[bb][j]+w2)%P;
				dp[bb][j+1]=(dp[bb][j+1]+w)%P;
				if(sz[id[i]]!=1){
					int t=dp[i][j]*2%P;
					dp[i+1][j]=(dp[i+1][j]+t)%P;
					dp[i+1][j+1]=(dp[i+1][j+1]+t)%P;
				}
			}
		}
		rep(i,l+1,r){
			int bb=ed[id[i]]+1;
			int up=min(i-l+1,k);
			rep(j,0,up)if(dp[i][j]){
				register int w=dp[i][j];
				if(sz[id[i]]!=1)w=(P-w);
				register int w2=(w+dp[i][j])%P;
				dp[bb][j]=(dp[bb][j]+w2)%P;
				dp[bb][j+1]=(dp[bb][j+1]+w)%P;
				if(sz[id[i]]!=1){
					int t=dp[i][j]*2%P;
					dp[i+1][j]=(dp[i+1][j]+t)%P;
					dp[i+1][j+1]=(dp[i+1][j+1]+t)%P;
				}
			}
		}
		int up=min(sz[y],k);
		rep(j,0,up)res[j]=(res[j]+P-dp[r+1][j])%P;
	}
	rep(i,1,q[0]){
		int x=q[i];
		sz[x]=fa[x]=0;inq[x]=0;
	}
}
void gkd(int yy){
	int x=gr(yy);
	work(x);
	vis[x]=1;
	for(int y:go[x])if(!vis[y])gkd(y);
}
int w[205][205];
int fac[205];
int main(){
	//n=100000;k=200;
	scanf("%d%d",&n,&k);
	rep(i,1,n-1){
		int a,b;
		a=i;b=i+1;
		scanf("%d%d",&a,&b);
		go[a].pb(b);
		go[b].pb(a);
	}
	gkd(1);
	w[0][0]=1;
	rep(i,1,k)rep(j,1,i)w[i][j]=(w[i-1][j-1]+w[i-1][j]*1ll*j)%P;
	fac[0]=1;rep(i,1,k)fac[i]=fac[i-1]*1ll*i%P;
	int ans=0;
	rep(i,0,k)ans=(ans+(w[k][i]*1ll*res[i]%P)*1ll*fac[i])%P;
	printf("%d\n",ans);
	//cerr<<po<<endl;
	return 0;
}