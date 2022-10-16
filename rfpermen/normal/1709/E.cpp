#include<bits/stdc++.h>
 
#pragma GCC optimize("O3")
#pragma GCC target("tune=native")
#pragma GCC optimize("unroll-loops")
 
using namespace std;
template<class A, class B>
ostream& operator<<(ostream& os, const pair<A, B> &p) {
  os << '(' << p.first << ',' << p.second << ')';
  return os;
}
template<class T>
ostream& operator<<(ostream& os, const vector<T> &v) {
  os << '{';
  bool osu = 1;
  for(auto &i : v) { if(!osu) os << ','; os << i; osu = 0; }
  os << '}';
  return os;
}
template<class T,long long unsigned int size>
ostream& operator<<(ostream& os, const array<T,size> &arr) {
  os << '{';
  bool osu = 1;
  for(auto &i : arr) { if(!osu) os << ','; os << i; osu = 0; }
  os << '}';
  return os;
}
 
#define ll long long
#define ull unsigned long long
#define lll __int128
#define rep(i,n,N) for(int i=(n);i<=(N);++i)
#define For(i,n,N) for(int i=(n);i< (N);++i)
#define rap(i,n,N) for(int i=(n);i>=(N);--i)
#define rip(i,n,N,V) for(int i=(n);i<=(N);i+=V)
#define mp make_pair
#define pb push_back
#define pob pop_back
#define pf push_front
#define pof pop_front
//#define le left
//#define ri right
#define fi first
#define se second
#define ff fi.fi
#define fs fi.se
#define sf se.fi
#define ss se.se
#define lc (id<<1)
#define rc ((id<<1)|1)
#define db(x) cout << ">>>> " << #x << " -> " << (x) << endl
#define out(x,y) cout << ">> " << (x) << " " << (y) << endl
#define ou3(x,y,z) cout << ">> " << (x) << " " << (y) << " " << (z) << endl
#define mems(x,y) memset(&x,y,sizeof x)
#define memsv(x,y) memset(&x[0], y, sizeof(x[0]) * x.size())
#define popcount __builtin_popcountll
#define clz(x) (1<<(31-__builtin_clz(x)))
#define clzll(x) (1LL<<(63-__builtin_clzll(x)))
#define all(x) x.begin(),x.end()
#define rsort(x) sort(x), reverse(x)
#define revsort(a,b) sort(a,b), reverse(a,b)
#define PQ(T) priority_queue<T>
#define PQr(T) priority_queue<T, vector<T>, greater<T>>
#define permute(x) while(next_permutation(all(x)))
#define vi vector<int>
#define vvi vector<vi>
#define vii vector<pii>
#define vll vector<ll>
#define vlll vector<pll>
#define vvll vector<vll>
#define ari(x) array<int,x>
#define arll(x) array<ll,x>
#define ard(x) array<double,x>
#define pii pair<int,int> 
#define pll pair<ll,ll>
#define plll pair<ll,pll>
#define pllll pair<pll,pll>
#define piii pair<int,pii>
#define piiii pair<pii,pii>
#define psi pair<string,int>
#define endl '\n'
const int MAX = 1e6+5;
const ll MOD = 1000000007;
const ll MOD2 = 2010405347;
const ll INF = 2e18;
const int dr[]={1,0,-1,0,1,1,-1,-1,0};
const int dc[]={0,1,0,-1,1,-1,1,-1,0};
const double pi = acos(-1);
const double EPS = 1e-9;
const int block = 547;
inline ll pw(ll x,ll y,ll md=MOD){ll ret=1;x%=md;while(y){if(y&1)ret=ret*x%md;x=x*x%md,y>>=1;}return ret;}
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

int n,x[MAX],a,b,ans,sz[MAX],at;
bool st[MAX];
set<int> s;
vi v[MAX],u[MAX],tmp;

bool cmp(int a,int b){
	return sz[a] > sz[b];
}

void gg(int nw,int par){
	sz[nw] = 1;
	for(int i:u[nw])if(i!=par){
		v[nw].pb(i);
		gg(i, nw);
		sz[nw]+= sz[i];
	}
	sort(all(v[nw]), cmp);
	return;
}

bool dfs(int nw,int val){
	if(st[nw])return 1;
	val^= x[nw];
//	db(val);
//	cout<<"<<>>> ";
//	for(auto i:s)cout<<i<<" "; cout<<endl;
	if(s.count(val^at))return 0;
	tmp.pb(val);
	for(int i:v[nw])if(!dfs(i, val))return 0;
	return 1;
}

void f(int nw,int val){
	val^= x[nw];
//	db(val);
	if(v[nw].empty()){
		s.insert(val);
		return;
	}
	For(i,1,v[nw].size()){
		f(v[nw][i], val);
		s.clear();
	}
	f(v[nw][0], val);
	at = x[nw];
	For(i,1,v[nw].size()){
		tmp.clear();
		if(!dfs(v[nw][i], val)){
			st[nw] = 1, ++ans;
			s.clear();
			return;
		}
//		db(v[nw][i]);
//		db(tmp);
		for(int j:tmp)s.insert(j);
	}
//	if(nw==3){
//		cout<<"<<>>> ";
//		for(auto i:s)cout<<i<<" "; cout<<endl;
//	}
	if(s.count(val^at)){
		st[nw] = 1, ++ans;
		s.clear();
	}
	else s.insert(val);
	return;
}

int main(){
//	cout<<fixed<<setprecision(6);
//	freopen("input.txt", "r", stdin);
//	freopen("output.txt","w",stdout);
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	cin>>n;
	rep(i,1,n)cin>>x[i];
	rep(i,2,n){
		cin>>a>>b;
		u[a].pb(b);
		u[b].pb(a);
	}
	gg(1,0);
//	rep(i,1,n)cout<<i<<" = "<<v[i]<<endl;
	f(1,0);
//	rep(i,1,n)cout<<st[i]; cout<<endl;
	cout<<ans<<endl;
	return 0;
}