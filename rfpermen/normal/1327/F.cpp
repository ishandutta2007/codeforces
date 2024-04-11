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
const int MAX = 5e5+5;
const ll MOD = 998244353;
const ll MOD2 = 2010405347;
const ll INF = 2e18;
const int dr[]={1,0,-1,0,1,1,-1,-1,0};
const int dc[]={0,1,0,-1,1,-1,1,-1,0};
const double pi = acos(-1);
const double EPS = 1e-9;
const int block = 5;
inline ll pw(ll x,ll y,ll md=MOD){ll ret=1;x%=md;while(y){if(y&1)ret=ret*x%md;x=x*x%md,y>>=1;}return ret;}
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

int n,k,m,l[MAX],r[MAX],mx[MAX],z[MAX],x[MAX],tree[1<<20],a,b,val;
ll ans,nw,dp[MAX];

void upd(int id,int le,int ri){
	if(le>b || ri<a)return;
	if(le>=a && ri<=b){
		tree[id]|= val;
		return;
	}
	int mid = le+ri>>1;
	upd(lc,le,mid), upd(rc,mid+1,ri);
	return;
}

void dfs(int id,int le,int ri){ // sejenis stabbing query
	if(le==ri){
		x[le] = tree[id];
		return;
	}
	int mid = le+ri>>1;
	tree[lc]|= tree[id];
	tree[rc]|= tree[id];
	dfs(lc,le,mid), dfs(rc,mid+1,ri);
	return;
}

int main(){
//	cout<<fixed<<setprecision(6);
//	freopen("input.txt", "r", stdin);
//	freopen("output.txt","w",stdout);
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	cin>>n>>k>>m;
	rep(i,1,m){
		cin>>l[i]>>r[i]>>z[i];
		a = l[i], b = r[i], val = z[i];
		upd(1,1,n);
	}
	dfs(1,1,n);
	
	int le;
	ans = 1;
	For(bit,0,k){
		mems(mx, 0);
		rep(i,1,m)if((z[i]&(1<<bit))==0){
			mx[r[i]] = max(mx[r[i]], l[i]);
		}
		// dp[x] menyatakan ada berapa banyak cara kalau yang terakhir kali dimatikan di pos x
		nw = dp[0] = 1;
		le = 0;
		rep(i,1,n){
			if(x[i]&(1<<bit)){
				dp[i] = 0;
			}
			else {
				dp[i] = nw;
				nw<<= 1;
			}
			//  misal yang dicover segmen 4..7 berarti dp[le], le<4 udh bikin impossible
			while(le<mx[i])nw-= dp[le], ++le;
			nw%= MOD;
		}
		ans = ans*nw % MOD;
	}
	if(ans<0)ans+= MOD;
	cout<<ans<<endl;
	return 0;
}