#include <bits/stdc++.h>
using namespace std;using ll=long long;using uint=unsigned int;using pii=pair<int,int>;using pll=pair<ll,ll>;using ull = unsigned long long;using ld=long double;template<typename T>void _(const char*s,T h){cerr<<s<<" = "<<h<<"\n";}template<typename T,typename...Ts>void _(const char*s,T h,Ts...t){int b=0;while(((b+=*s=='(')-=*s==')')!=0||*s!=',')cerr<<*s++;cerr<<" = "<<h<<",";_(s+1,t...);}// break continue pop_back 998244353
#define int ll
#define pii pll
#define f first
#define s second
#define pb emplace_back
#define forn(i,n) for(int i=0;i<(n);++i)
#define sz(a)((int)(a).size())
#define sqr(x) ((x)*(x))
struct init{init(){cin.tie(0);iostream::sync_with_stdio(0);cout<<fixed<<setprecision(10);cerr<<fixed<<setprecision(5);}~init(){
#ifdef LOCAL
#define dbg(...) _(#__VA_ARGS__,__VA_ARGS__)
cerr<<"Time elapsed: "<<(double)clock()/CLOCKS_PER_SEC<<"s.\n";
#else
#define dbg(...) 
#endif
}}init;template<typename T,typename U>void upx(T&x,U y){if(x<y)x=y;}template<typename T,typename U>void upn(T&x,U y){if(x>y)x=y;}mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());const int D=4,dx[]={+1,0,-1,0},dy[]={0,+1,0,-1};

const int N=101010,OO=1e9;
int x[N],y[N],t[N];
int dp[N],q[N];
int32_t main(){
	int XX,n;
	cin>>XX>>n;
	x[0]=y[0]=1;
	int l=0,r=0;
	q[r++]=0;
	int ans=0,old=-OO;
	for(int32_t i=1;i<=n;++i){
		cin>>t[i]>>x[i]>>y[i];
		dp[i]=old;
		for(int k=l;k<r;++k){
			int j=q[k];
			if(abs(x[i]-x[j])+abs(y[i]-y[j])<=t[i]-t[j]){
				upx(dp[i],dp[j]+1);
			}
		}
		if(dp[i]>=0){
			q[r++]=i;
			if(r-l>2000)upx(old,dp[q[l++]]);
		}
		upx(ans,dp[i]);
	}
	cout<<ans<<'\n';

    return 0;
}