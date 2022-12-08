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
using namespace std;

const int N=200005,M=100005,mod=1e9+7;
template<class T> inline void gmin(T &x,const T &y){if(x>y) x=y;}
template<class T> inline void gmax(T &x,const T &y){if(x<y) x=y;}
inline void ch(int &x,int y){x+=y;if(x>=mod) x-=mod;}

inline int gcd(int x,int y){return y?gcd(y,x%y):x;}
int n,m,f[N],dp[N],from[N],now=1;
vi ans,g[N];
bool vis[N],go[N];

inline void gcd(int x,int y,int &a,int &b){
	if(!y){
		a=1;b=0;
		return ;
	}
	int ta,tb;gcd(y,x%y,ta,tb);
	a=tb;b=-tb*(x/y)+ta;
}
int inv(int x,int mod){
	int a,b;
	gcd(x,mod,a,b);
	return a=(a%mod+mod)%mod;
}
int get(int x,int y,int mod){
//	printf("%d %d %d\n",x,y,mod);
	return (ll)y*inv(x,mod)%mod;
}

void solve(int x){
	if(x!=1&&x!=from[x]) solve(from[x]);
	if(x==m&&g[x].size()>0){ans.pb(0);return;}
	for(int i:g[x]){
		int p=gcd(now,m),q=gcd(i,m),k=1;
		if(p!=q) k=q/p;
		k=(ll)k*get(now/p,i/q,m/p)%m;
		ans.pb(k);now=i;
	}
}

int main(){
	scanf("%d%d",&n,&m);
	for(int i=1;i<=m;i++) f[gcd(i,m)]++,go[gcd(i,m)]=1;
	for(int i=1;i<=n;i++){
		int x;scanf("%d",&x);
		vis[x]=1;f[gcd(x,m)]--;
	}
	for(int i=0;i<m;i++)
		if(!vis[i]) g[gcd(i,m)].pb(i);
	for(int i=1;i<=m;i++) dp[i]=f[i],from[i]=i;
	for(int i=1;i<=m;i++){
		if(!go[i]) continue;
		for(int j=i+i;j<=m;j+=i)
			if(dp[i]+f[j]>dp[j]) dp[j]=f[j]+dp[i],from[j]=i;
	}
	printf("%d\n",dp[m]);
	solve(m);
	for(auto i:ans)printf("%d ",i);
	puts("");
//	int now=1;for(auto i:ans) now=(ll)now*i%m,printf("%d ",now);
	return 0;
}