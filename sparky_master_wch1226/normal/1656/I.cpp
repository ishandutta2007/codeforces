#ifndef LOCAL
#pragma GCC optimize ("Ofast")
#pragma GCC optimize ("unroll-loops")
#endif

#include <bits/stdc++.h>
using namespace std;

using ll=long long;
//#define int ll

#define rng(i,a,b) for(int i=int(a);i<int(b);i++)
#define rep(i,b) rng(i,0,b)
#define gnr(i,a,b) for(int i=int(b)-1;i>=int(a);i--)
#define per(i,b) gnr(i,0,b)
#define pb push_back
#define eb emplace_back
#define a first
#define b second
#define bg begin()
#define ed end()
#define all(x) x.bg,x.ed
#define si(x) int(x.size())
#ifdef LOCAL
#define dmp(x) cerr<<__LINE__<<" "<<#x<<" "<<x<<endl
#else
#define dmp(x) void(0)
#endif

template<class t,class u> bool chmax(t&a,u b){if(a<b){a=b;return true;}else return false;}
template<class t,class u> bool chmin(t&a,u b){if(b<a){a=b;return true;}else return false;}

template<class t> using vc=vector<t>;
template<class t> using vvc=vc<vc<t>>;

using pi=pair<int,int>;
using vi=vc<int>;

template<class t,class u>
ostream& operator<<(ostream& os,const pair<t,u>& p){
	return os<<"{"<<p.a<<","<<p.b<<"}";
}

template<class t> ostream& operator<<(ostream& os,const vc<t>& v){
	os<<"{";
	for(auto e:v)os<<e<<",";
	return os<<"}";
}

#define mp make_pair
#define mt make_tuple
#define one(x) memset(x,-1,sizeof(x))
#define zero(x) memset(x,0,sizeof(x))
#ifdef LOCAL
void dmpr(ostream&os){os<<endl;}
template<class T,class... Args>
void dmpr(ostream&os,const T&t,const Args&... args){
	os<<t<<" ";
	dmpr(os,args...);
}
#define dmp2(...) dmpr(cerr,__LINE__,##__VA_ARGS__)
#else
#define dmp2(...) void(0)
#endif

using uint=unsigned;
using ull=unsigned long long;

template<class t,size_t n>
ostream& operator<<(ostream&os,const array<t,n>&a){
	return os<<vc<t>(all(a));
}

template<int i,class T>
void print_tuple(ostream&,const T&){
}

template<int i,class T,class H,class ...Args>
void print_tuple(ostream&os,const T&t){
	if(i)os<<",";
	os<<get<i>(t);
	print_tuple<i+1,T,Args...>(os,t);
}

template<class ...Args>
ostream& operator<<(ostream&os,const tuple<Args...>&t){
	os<<"{";
	print_tuple<0,tuple<Args...>,Args...>(os,t);
	return os<<"}";
}

template<class t>
void print(t x,int suc=1){
	cout<<x;
	if(suc==1)
		cout<<"\n";
	if(suc==2)
		cout<<" ";
}

ll read(){
	ll i;
	cin>>i;
	return i;
}

vi readvi(int n,int off=0){
	vi v(n);
	rep(i,n)v[i]=read()+off;
	return v;
}

pi readpi(int off=0){
	int a,b;cin>>a>>b;
	return pi(a+off,b+off);
}

template<class t,class u>
void print(const pair<t,u>&p,int suc=1){
	print(p.a,2);
	print(p.b,suc);
}

template<class T>
void print(const vector<T>&v,int suc=1){
	rep(i,v.size())
		print(v[i],i==int(v.size())-1?suc:2);
}

template<class T>
void print_offset(const vector<T>&v,ll off,int suc=1){
	rep(i,v.size())
		print(v[i]+off,i==int(v.size())-1?suc:2);
}

template<class T,size_t N>
void print(const array<T,N>&v,int suc=1){
	rep(i,N)
		print(v[i],i==int(N)-1?suc:2);
}

string readString(){
	string s;
	cin>>s;
	return s;
}

template<class T>
T sq(const T& t){
	return t*t;
}

#define CAPITAL
void yes(bool ex=true){
	#ifdef CAPITAL
	cout<<"YES"<<"\n";
	#else
	cout<<"Yes"<<"\n";
	#endif
	if(ex)exit(0);
	#ifdef LOCAL
	cout.flush();
	#endif
}
void no(bool ex=true){
	#ifdef CAPITAL
	cout<<"NO"<<"\n";
	#else
	cout<<"No"<<"\n";
	#endif
	if(ex)exit(0);
	#ifdef LOCAL
	cout.flush();
	#endif
}
void possible(bool ex=true){
	#ifdef CAPITAL
	cout<<"POSSIBLE"<<"\n";
	#else
	cout<<"Possible"<<"\n";
	#endif
	if(ex)exit(0);
	#ifdef LOCAL
	cout.flush();
	#endif
}
void impossible(bool ex=true){
	#ifdef CAPITAL
	cout<<"IMPOSSIBLE"<<"\n";
	#else
	cout<<"Impossible"<<"\n";
	#endif
	if(ex)exit(0);
	#ifdef LOCAL
	cout.flush();
	#endif
}

constexpr ll ten(int n){
	return n==0?1:ten(n-1)*10;
}

const ll infLL=LLONG_MAX/3;

#ifdef int
const int inf=infLL;
#else
const int inf=INT_MAX/2-100;
#endif

int topbit(signed t){
	return t==0?-1:31-__builtin_clz(t);
}
int topbit(ll t){
	return t==0?-1:63-__builtin_clzll(t);
}
int botbit(signed a){
	return a==0?32:__builtin_ctz(a);
}
int botbit(ll a){
	return a==0?64:__builtin_ctzll(a);
}
int popcount(signed t){
	return __builtin_popcount(t);
}
int popcount(ll t){
	return __builtin_popcountll(t);
}
bool ispow2(int i){
	return i&&(i&-i)==i;
}
ll mask(int i){
	return (ll(1)<<i)-1;
}

bool inc(int a,int b,int c){
	return a<=b&&b<=c;
}

template<class t> void mkuni(vc<t>&v){
	sort(all(v));
	v.erase(unique(all(v)),v.ed);
}

ll rand_int(ll l, ll r) { //[l, r]
	#ifdef LOCAL
	static mt19937_64 gen;
	#else
	static mt19937_64 gen(chrono::steady_clock::now().time_since_epoch().count());
	#endif
	return uniform_int_distribution<ll>(l, r)(gen);
}

template<class t>
void myshuffle(vc<t>&a){
	rep(i,si(a))swap(a[i],a[rand_int(0,i)]);
}

template<class t>
int lwb(const vc<t>&v,const t&a){
	return lower_bound(all(v),a)-v.bg;
}

vvc<int> readGraph(int n,int m){
	vvc<int> g(n);
	rep(i,m){
		int a,b;
		cin>>a>>b;
		//sc.read(a,b);
		a--;b--;
		g[a].pb(b);
		g[b].pb(a);
	}
	return g;
}

vvc<int> readTree(int n){
	return readGraph(n,n-1);
}

// tr 
//
// x  -> tr[n+x]
//
//s  biconnected components 
//es  biconnected componenents 
//
//VERIFY
//Petrozavodsk Camp 2020S Day2 C
//TCO2020 Wildcard Hard
//CF CodeTON Round I
template<class E>
struct articulation{
	const int n;
	const vvc<E>&g;
	vi vis,ord,low;
	int head,s;
	vvc<int> tr;
	vvc<pi> es;
	void ae(int a,int b){
		if(a==-1||b==-1)return;
		tr[a].pb(b);
		tr[b].pb(a);
	}
	void dfs(int v){
		assert(vis[v]==0);
		vis[v]=1;
		ord[v]=low[v]=head++;
		for(auto to:g[v]){
			if(vis[to]==0){
				dfs(to);
				chmin(low[v],low[to]);
			}else{
				chmin(low[v],ord[to]);
			}
		}
	}
	void dfs2(int v,int z){
		assert(vis[v]==1);
		vis[v]=2;
		ae(v,z);
		for(auto to:g[v])if(vis[to]==1){
			if(low[to]<ord[v]){
				dfs2(to,z);
			}else{
				int w=si(tr);
				tr.eb();
				es.eb();
				s++;
				ae(v,w);
				dfs2(to,w);
			}
		}else if(vis[to]==2){
			es[z-n].eb(v,to);
		}
		vis[v]=3;
	}
	articulation(const vvc<E>&gg):n(si(gg)),g(gg),
		vis(n,0),ord(n,-1),low(n,-1),head(0),s(0),tr(n){
		rep(i,n)if(vis[i]==0){
			dfs(i);
			dfs2(i,-1);
		}
	}
	// i 
	pair<vi,vc<pi>> getg(int i){
		vi vs=tr[n+i];
		sort(all(vs));
		vc<pi> res=es[i];
		for(auto&[a,b]:res){
			a=lwb(vs,a);
			b=lwb(vs,b);
		}
		return mp(vs,res);
	}
};

// outerplanar 
// {} 
// p[v] =  v  
//p[0]=0
vi outer_cycle(int n,vc<pi> es){
	vc<set<int>> g(n);
	for(auto [a,b]:es){
		g[a].insert(b);
		g[b].insert(a);
	}
	vc<bool> added(n);
	vi ls;
	auto add=[&](int i){
		if(!added[i]&&si(g[i])==2){
			added[i]=true;
			ls.pb(i);
		}
	};
	rep(i,n)add(i);
	vc<pi> nb(n,pi(-1,-1));
	vi idx;
	rep(_,n-2){
		if(ls.empty())return {};
		int v=ls.back();ls.pop_back();
		if(si(g[v])!=2)return {};
		auto itr=g[v].bg;
		int a=*itr;
		++itr;
		int b=*itr;
		idx.pb(v);
		nb[v]=pi(a,b);
		g[a].erase(v);
		g[b].erase(v);
		g[a].insert(b);
		g[b].insert(a);
		add(a);
		add(b);
	}
	vi pr(n,-1),nx(n,-1);
	auto link=[&](int a,int b){
		nx[a]=b;
		pr[b]=a;
	};
	{
		int a=-1,b=-1;
		rep(i,n)if(nb[i]==pi(-1,-1)){
			if(a==-1)a=i;
			else{
				assert(b==-1);
				b=i;
			}
		}
		assert(b!=-1);
		link(a,b);
		link(b,a);
	}
	reverse(all(idx));
	for(auto v:idx){
		auto [a,b]=nb[v];
		if(nx[a]!=b)swap(a,b);
		if(nx[a]!=b)return {};
		link(a,v);
		link(v,b);
	}
	vi p(n);
	for(int cur=0,ord=0;ord<n;cur=nx[cur],ord++){
		p[cur]=ord;
	}
	return p;
}

void slv(){
	int n,m;cin>>n>>m;
	vvc<int> g(n);
	rep(i,m){
		int a,b;cin>>a>>b;
		g[a].pb(b);
		g[b].pb(a);
	}
	vvc<int> ans(n);
	articulation art(g);
	rep(bci,art.s){
		auto [vs,es]=art.getg(bci);
		int s=si(vs);
		vi p=outer_cycle(s,es);
		if(p.empty())return no(0);
		vvc<int> h(s);
		for(auto [a,b]:es){
			h[a].pb(b);
			h[b].pb(a);
		}
		rep(v,s){
			auto dif=[&](int i){
				int d=p[i]-p[v];
				if(d<0)d+=s;
				return d;
			};
			sort(all(h[v]),[&](int i,int j){return dif(i)>dif(j);});
			for(auto to:h[v])
				ans[vs[v]].pb(vs[to]);
		}
	}
	yes(0);
	rep(i,n)print(ans[i]);
}

signed main(){
	cin.tie(0);
	ios::sync_with_stdio(0);
	cout<<fixed<<setprecision(20);
	
	int t;cin>>t;rep(_,t)
	slv();
}