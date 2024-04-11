#include <bits/stdc++.h>
using namespace std;using ll=long long;using uint=unsigned int;using pii=pair<int,int>;using pll=pair<ll,ll>;using ull = unsigned long long;using ld=long double;template<typename T>void _(const char*s,T h){cerr<<s<<" = "<<h<<"\n";}template<typename T,typename...Ts>void _(const char*s,T h,Ts...t){int b=0;while(((b+=*s=='(')-=*s==')')!=0||*s!=',')cerr<<*s++;cerr<<" = "<<h<<",";_(s+1,t...);}// break continue pop_back 998244353
// #define int ll
// #define pii pll
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

const int N=303030;
vector<int> g1[N],g2[N];
int l[N],r[N];
int timer;
void dfs2(int v){
	l[v]=timer++;
	for(int to:g2[v])dfs2(to);
	r[v]=timer++;
}
set<pii> s;
int ans;
void dfs1(int v){
	pii pop={-1,-1};
	auto p=s.upper_bound({l[v],r[v]});
	if(p!=s.begin()){
		p=prev(p);
		pii q=*p;
		if(q.s>=r[v]){
			pop=q;
			s.erase(p);
		}
	}
	p=s.upper_bound({l[v],r[v]});
	int ok=1;
	if(p!=s.end()){
		pii q=*p;
		if(q.s<=r[v]){
			ok=0;
		}
	}
	if(ok)s.insert({l[v],r[v]});
	upx(ans,sz(s));
	for(int to:g1[v])dfs1(to);
	if(pop.f!=-1)s.insert(pop);
	if(ok)s.erase({l[v],r[v]});
}
int32_t main(){
	int t;
	cin>>t;
	while(t--){
		int n;
		cin>>n;
		for(int i=1;i<=n;++i){
			g1[i].clear();
			g2[i].clear();
		}
		timer=ans=0;
		for(int i=2;i<=n;++i){
			int p;
			cin>>p;
			g1[p].pb(i);
		}
		for(int i=2;i<=n;++i){
			int p;
			cin>>p;
			g2[p].pb(i);
		}
		dfs2(1);
		dfs1(1);
		cout<<ans<<'\n';
	}
    return 0;
}