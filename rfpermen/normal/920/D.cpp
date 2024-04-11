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
//#define lc (id<<1)
//#define rc ((id<<1)|1)
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
const int MAX = 5e3+5;
const ll MOD = 1000000007;
const ll MOD2 = 2010405347;
const ll INF = 2e18;
const int dr[]={1,0,-1,0,1,1,-1,-1,0};
const int dc[]={0,1,0,-1,1,-1,1,-1,0};
const double pi = acos(-1);
const double EPS = 1e-9;
const int block = 5;
inline ll pw(ll x,ll y,ll md=MOD){ll ret=1;x%=md;while(y){if(y&1)ret=ret*x%md;x=x*x%md,y>>=1;}return ret;}
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

int n,k,tg,v,x[MAX],sm,dp[MAX][MAX];
vi z;
bool st[MAX];

int f(int nw,int rem){
	if(rem==tg)return 1;
	if(nw>n)return 0;
	int &ret = dp[nw][rem];
	if(ret!=-1)return ret;
	return ret = f(nw+1,rem) || f(nw+1,(rem+x[nw])%k);
}

void bt(int nw,int rem){
	if(rem==tg)return;
	int &ret = dp[nw][rem];
	if(f(nw+1,rem))bt(nw+1,rem);
	else {
		z.pb(nw);
		st[nw] = 1;
		bt(nw+1,(rem+x[nw])%k);
	}
	return;
}

inline void mov(int vol,int a,int b){
	int cnt = (min(vol, x[a])+k-1)/k;
	if(!cnt)return;
	vol = min(cnt*k, x[a]);
	cout<<cnt<<" "<<a<<" "<<b<<endl;
	x[a]-= vol;
	x[b]+= vol;
	return;
}

inline void run(){
	rep(i,1,n)cout<<x[i]<<" "; cout<<endl;
	exit(0);
}

int main(){
//	cout<<fixed<<setprecision(10);
//	freopen("input.txt", "r", stdin);
//	freopen("output.txt","w",stdout);
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	cin>>n>>k>>v;
	tg = v%k;
	rep(i,1,n)cin>>x[i], sm+= x[i];
	mems(dp,-1);
	if(sm<v || !f(1,0))return cout<<"NO\n",0;
	cout<<"YES\n";
	bt(1,0);
	if(tg==0){
		z.pb(1);
		st[1] = 1;
		mov(MOD, 1, 2);
	}
	For(i,1,z.size())mov(MOD, z[i], z[0]);
	if(x[z[0]] > v){
		if(z[0]==n)tg = 1;
		else tg = n;
		mov(x[z[0]]-v, z[0], tg);
	}
	tg = z[0];
	z.clear();
	rep(i,1,n)if(!st[i])z.pb(i);
	For(i,1,z.size())mov(MOD, z[i], z[0]);
	if(z.size())mov(v-x[tg], z[0], tg);
//	run();
	return 0;
}