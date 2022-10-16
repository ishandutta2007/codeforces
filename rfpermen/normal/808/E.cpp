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
const int MAX = 2e5+5;
const ll MOD = 1000000007;
const ll MOD2 = 2010405347;
const ll INF = 2e18;
const int dr[]={1,0,0,-1,1,1,-1,-1};
const int dc[]={0,-1,1,0,1,-1,1,-1};
const double pi = acos(-1);
const double EPS = 1e-9;
const int block = 8;
inline ll pw(ll x,ll y,ll md=MOD){ll ret=1;x%=md;while(y){if(y&1)ret=ret*x%md;x=x*x%md,y>>=1;}return ret;}
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

ll n,w,sm,ttl,dp[300][100],a;
pll x[MAX];
vi z[5];
bool st[MAX];

bool cmp(pll a,pll b){
	return a.se*b.fi > b.se*a.fi;
}

ll f(int nw,int rem){
	if(rem<0)return -INF;
	if(nw>n)return 0;
	ll &ret = dp[nw][rem];
	if(ret!=-1)return ret;
	return ret = max(f(nw+1,rem), f(nw+1,rem-x[nw].fi) + x[nw].se);
}

int main(){
//	cout<<fixed<<setprecision(10);
//	freopen("input.txt", "r", stdin);
//	freopen("output.txt","w",stdout);
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	cin>>n>>w;
	rep(i,1,n){
		cin>>x[i].fi>>x[i].se;
		ttl+= x[i].fi;
		sm+= x[i].se;
	}
	if(ttl<=w)return cout<<sm<<endl,0;
	sort(x+1,x+1+n,cmp);
	sm = 0;
	rep(i,1,n)if(w>=x[i].fi){
		w-= x[i].fi;
		sm+= x[i].se;
		st[i] = 1;
		z[x[i].fi].pb(i);
	}
	rep(i,1,3){
		rep(j,1,15){
			if(z[i].empty())break;
			w+= i;
			a = z[i].back();
			z[i].pob();
			sm-= x[a].se;
			st[a] = 0;
		}
	}
	rep(i,1,3)z[i].clear();
	rep(i,1,n)if(!st[i])z[x[i].fi].pb(x[i].se);
	n = 0;
	rep(i,1,3){
		rsort(all(z[i]));
		a = min((int)z[i].size(), 95);
		For(j,0,a)x[++n] = {i, z[i][j]};
	}
	mems(dp, -1);
	cout<<sm+f(1,w)<<endl;
	return 0;
}