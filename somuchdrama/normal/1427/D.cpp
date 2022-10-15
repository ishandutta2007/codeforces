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
int a[N],b[N];
int32_t main(){
	int n;
	cin>>n;
	forn(i,n)cin>>a[i];
	int t=n&1;

	vector<vector<int>> ans;
	forn(i,n){
		int f;
		forn(j,n)if(a[j]==i+1)f=j;
		vector<int> v;
		if(t){
			if(f)v.pb(f);
			v.pb(n-i-f);
			forn(j,i)v.pb(1);
		}else{
			forn(j,i)v.pb(1);
			v.pb(f-i+1);
			if(n-f-1)v.pb(n-f-1);
		}
		t^=1;
		if(sz(v)>1){
			ans.pb(v);
		}

		int pos=0,start=n;
		reverse(v.begin(), v.end());
		for(int j:v){
			start-=j;
			forn(x,j)
				b[pos++]=a[start+x];
		}
		forn(j,n)a[j]=b[j];
		cerr<<"A: ";
		forn(j,n)cerr<<a[j]<<' ';
		cerr<<'\n';
	}

	cout<<sz(ans)<<'\n';
	for(auto v:ans){
		cout<<sz(v)<<' ';
		for(int j:v)cout<<j<<' ';
		cout<<'\n';
	}

    return 0;
}