#include<bits/stdc++.h>
#define sqr(x) ((x)*(x))
#define ll long long
#define ull unsigned long long
#define ui unsigned int
#define ld long double
#define vi vector<int>
#define pii pair<int,int>
#define pb push_back
#define mp make_pair
#define debuge cerr<<"isok"<<endl
#define debug(x) cerr<<#x<<"="<<x<<endl
#define SS second
#define FF first
#define ls (k<<1)
#define rs (k<<1|1)
#define inf 0x3f3f3f3f
#define clr(a,x) memset(a,x,sizeof(a))
#define cpy(a,x) memcpy(a,x,sizeof(a))
#define file(x) freopen(x".in","r",stdin),freopen(x".out","w",stdout);
using namespace std;

const int N=255,M=100005,mod=998244353;
template<class T> inline void gmin(T &x,const T &y){if(x>y) x=y;}
template<class T> inline void gmax(T &x,const T &y){if(x<y) x=y;}
inline void ch(int &x,int y){x=(x+y)%mod;}
inline void read(int &x){
	x=0;char ch=getchar(),rev=0;
	while(ch>'9'||ch<'0') rev=(ch=='-'),ch=getchar();
	while(ch>='0'&&ch<='9') x=x*10+ch-'0',ch=getchar();
	x=rev?-x:x;
}
inline int exp(int x,int y){
	int ans=1;
	while(y){
		if(y&1) ans=(ll)ans*x%mod;
		x=(ll)x*x%mod;y>>=1;
	}return ans;
}
 
int n,m,a[N],b[N],dp[N][N],fac[N],ifac[N],sum[N];
int pos[N],cnt[2][2],si,cir,ans[N],L[N],f[N][N];
bool vb[N],vis[N];

void pre(){
	ifac[0]=fac[0]=1;
	for(int i=1;i<=n;i++) fac[i]=(ll)fac[i-1]*i%mod;
	for(int i=0;i<=n;i++) ifac[i]=exp(fac[i],mod-2);
	dp[0][0]=sum[0]=1;
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++)
			dp[i][j]=(ll)sum[j-1]*fac[i-1]%mod;
		for(int j=1;j<=n;j++)
			ch(sum[j],(ll)dp[i][j]*ifac[i]%mod);
	}
//	for(int i=7;i;i--) printf("%d ",dp[7][i]);puts("");
}

int main(){
#ifdef rqgao2014
	freopen("input.txt","r",stdin);
#endif 
	read(n);m=n;pre();
	for(int i=1;i<=n;i++){
		read(a[i]);
		if(a[i]) pos[a[i]]=i,m--;
	}
	for(int i=1;i<=n;i++){
		read(b[i]);
		if(b[i]) vb[b[i]]=1,si++,m-=(!pos[b[i]]);
	}
//	debug(m);
	for(int i=1;i<=n;i++){
		if(vb[a[i]]||vis[i]) continue;
		int k=i,in=(!a[i]),out=0;
		vis[i]=1;
		while(b[k]){
			if(b[k]&&!pos[b[k]]){out=1;break;}
			k=pos[b[k]];vis[k]=1;
		}
		cnt[in][out]++;
	}
	f[0][0]=1;
	for(int i=1;i<=cnt[1][0];i++){
		int sum=0;
		for(int j=0;j<=cnt[1][1];j++){
			ch(sum,(ll)f[i-1][j]*fac[cnt[1][1]-j]%mod);
			f[i][j]=(ll)sum*ifac[cnt[1][1]-j]%mod;
		}
	}
	for(int j=0;j<=cnt[1][1];j++)
		for(int k=0;k<=cnt[1][1]-j;k++)
			ch(L[k],(ll)f[cnt[1][0]][j]*dp[cnt[1][1]-j][k]%mod);
	for(int i=1;i<=n;i++){
		if(vis[i]) continue;
		int k=i;
		while(!vis[k]) vis[k]=1,k=pos[b[k]];
		cir++;
	}
	for(int i=0;i<=cnt[1][1];i++)
		for(int j=0;j<=n-si;j++)
			ch(ans[i+j+cir],(ll)L[i]*dp[n-si][j]%mod);
	for(int i=1;i<=n;i++) ans[i]=(ll)ans[i]*fac[m]%mod*fac[cnt[1][0]]%mod*ifac[cnt[1][0]-cnt[0][1]]%mod;
	for(int i=n;i;i--) printf("%d ",ans[i]);puts("");
	return 0;
}