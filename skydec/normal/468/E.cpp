#include<cstring>
#include<cstdlib>
#include<cstdio>
#include<cmath>
#include<algorithm>
#include<map>
#include<set>
#include<string>
#include<vector>
#include<assert.h>
#define pb push_back
#define rep(i,j,k) for(int i=(j);i<=(int)k;i++)
#define per(i,j,k) for(int i=(j);i>=(int)k;i--)
#define lowbit(x) ((x)&(-(x)))
#define fi first
#define se second
#define pii pair<int,int>
#define VI vector<int>
#define S(x) x.size()
using namespace std;
typedef long long LL;
typedef double db;
const int N=210000;
const int P=1000000007;
inline int Pow(int a,int b){
	int c=1;
	for(;b;b>>=1,a=a*1ll*a%P)if(b&1)c=c*1ll*a%P;
	return c;
}
int n,k;
int head[N],p[N],np[N],w[N];int tot;
inline void link(int a,int b,int v){
	++tot;p[tot]=b;np[tot]=head[a];head[a]=tot;w[tot]=v;
}
int res[155];
bool use[N];
int st[N],ed[N],val[N];
int cho[N];
int F[2][N][55];
int tmp0[155],tmp1[155];
bool cb[N*2];
bool vp[N*2];
void Gettree(int x,int y){
	vp[x]=1;
	for(int u=head[x];u;u=np[u])if(p[u]^y){
		if(!vp[p[u]]){
			Gettree(p[u],x);
			cb[u]=1;
		}
	}
	else cb[u]=1;
}
int dfs(int x){
	int sz=1;cho[x]=1;
	memset(F[0][x],0,sizeof F[0][x]);
	memset(F[1][x],0,sizeof F[1][x]);
	F[0][x][0]=1;
	
	for(int u=head[x];u;u=np[u])if(!cho[p[u]]){
		int v=p[u];
		int t=dfs(v);
		sz+=t;
		
		rep(i,0,sz){
			tmp0[i]=F[0][x][i];
			tmp1[i]=F[1][x][i];
			F[0][x][i]=F[1][x][i]=0;
		}
		
		rep(i,0,sz)for(int j=0;j<=t&&j<=i;j++)
		F[0][x][i]=(F[0][x][i]+1ll*F[0][v][j]*tmp0[i-j])%P;
		
		rep(i,0,sz)for(int j=0;j<=t&&j<=i;j++)
		F[0][x][i]=(F[0][x][i]+1ll*F[1][v][j]*tmp0[i-j])%P;
		
		rep(i,0,sz)for(int j=0;j<=t&&j<=i;j++)
		F[1][x][i]=(F[1][x][i]+1ll*F[1][v][j]*tmp1[i-j])%P;
		
		rep(i,0,sz)for(int j=0;j<=t&&j<=i;j++)
		F[1][x][i]=(F[1][x][i]+1ll*F[0][v][j]*tmp1[i-j])%P;
		
		if(!use[x]){
			rep(i,0,sz)for(int j=0;j<=t&&j<=i;j++)
			F[1][x][i+2]=(F[1][x][i+2]+((1ll*F[0][v][j]*tmp0[i-j])%P)*1ll*w[u])%P;
		}
	}
	
	if(use[x]){
		rep(i,0,sz){
			F[1][x][i]=F[0][x][i];
			F[0][x][i]=0;
		}
	}
	
	return sz;
}
inline void tree_dp(vector<int> List){
	int top=0;
	
	Gettree(List[0],0);
	
	rep(i,0,List.size()-1){
		int x=List[i];
		for(int u=head[x];u;u=np[u])if(x<p[u]&&cb[u]==0){
			st[++top]=x;ed[top]=p[u];val[top]=w[u];
		}
	}
	
	memset(res,0,sizeof res);
	rep(i,0,(1<<top)-1){
		int Ret=1;memset(use,0,sizeof use);int pp=0;
		rep(j,0,top-1)if((1<<j)&i){
			Ret=Ret*1ll*val[j+1]%P;pp++;
			if(use[st[j+1]]){Ret=0;break;}
			if(use[ed[j+1]]){Ret=0;break;}
			use[st[j+1]]=use[ed[j+1]]=1;
		}
		if(Ret==0)continue;
		
		rep(j,0,List.size()-1)cho[List[j]]=0;
		dfs(List[0]);
		rep(j,0,List.size()/2){
			res[j+pp]=(res[j+pp]+F[0][List[0]][j*2]*1ll*Ret)%P;
			res[j+pp]=(res[j+pp]+F[1][List[0]][j*2]*1ll*Ret)%P;
		}
	}
}
int f[(1<<16)+5];
int g[(1<<16)+5];
int idx[N];
inline int Cot(int x){
	int ret=0;
	while(x){
		ret+=(x%2==1);
		x/=2;
	}
	return ret;
}
inline void count_dp(vector<int> List){
	int M=List.size();
	
	vector<int>small;
	vector<int>big;
	small.clear();big.clear();
	
	rep(i,0,M-1){
		if(List[i]<=n)small.pb(List[i]);
		else big.pb(List[i]);
	}
	
	if(small.size()>big.size())swap(small,big);
	
	M=small.size();rep(i,0,M-1)idx[small[i]]=i;
	
	assert(M<=16);
	
	rep(i,0,(1<<M)-1)f[i]=g[i]=0;
	f[0]=1;
	
	rep(i,0,big.size()-1){
		int x=big[i];
		rep(j,0,(1<<M)-1){
			for(int u=head[x];u;u=np[u])if(!((1<<idx[p[u]])&j))g[j+(1<<(idx[p[u]]))]=(g[j+(1<<(idx[p[u]]))]+f[j]*1ll*w[u])%P;
			g[j]=(g[j]+f[j])%P;
		}
		
		rep(j,0,(1<<M)-1){
			f[j]=g[j];g[j]=0;
		}
	}
	memset(res,0,sizeof res);
	rep(j,0,(1<<M)-1)res[Cot(j)]=(res[Cot(j)]+f[j])%P;
}
int fac[N],inv[N];bool vis[N];
int List[N];
int ans[155];int tmq[155];
inline void Merge_ans(){
	memset(tmq,0,sizeof tmq);
	rep(i,0,k)rep(j,0,k)tmq[i+j]=(tmq[i+j]+ans[i]*1ll*res[j])%P;
	rep(i,0,2*k)ans[i]=tmq[i];
}
int main(){
	scanf("%d%d",&n,&k);
	fac[0]=1;ans[0]=1;
	rep(i,1,n)fac[i]=fac[i-1]*1ll*i%P;
	inv[n]=Pow(fac[n],P-2);
	per(i,n-1,0)inv[i]=inv[i+1]*1ll*(i+1)%P;
	
	rep(i,1,k){
		int x,y,v;scanf("%d%d%d",&x,&y,&v);v--;
		link(x,y+n,v);link(y+n,x,v);
	}
	
	rep(i,1,2*n)if(!vis[i]&&head[i]){
		vis[i]=1;
		vector<int>que;que.clear();que.pb(i);
		
		for(int j=0;j<(int)que.size();j++){
			int x=que[j];
			for(int u=head[x];u;u=np[u])if(!vis[p[u]]){
				vis[p[u]]=1;que.pb(p[u]);
			}
		}
		
		if(que.size()<=32)count_dp(que);
		else tree_dp(que);
		
		Merge_ans();
	}
	int rp=0;
	
	rep(i,0,k)rp=(rp+fac[n-i]*1ll*ans[i])%P;
	printf("%d\n",(rp+P)%P);
	return 0;
}