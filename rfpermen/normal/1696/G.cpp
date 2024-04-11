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
const int dr[]={1,0,-1,0,1,1,-1,-1,0};
const int dc[]={0,1,0,-1,1,-1,1,-1,0};
const double pi = acos(-1);
const double EPS = 1e-9;
const int block = 20;
inline ll pw(ll x,ll y,ll md=MOD){ll ret=1;x%=md;while(y){if(y&1)ret=ret*x%md;x=x*x%md,y>>=1;}return ret;}
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

int n,q,z[MAX],op,a,b;
double x,y,ans;

using ST = array<array<double, 3>, 3>;
ST tree[1<<19], ret;

// Ini dapet solusinya dari baca editorial sih
// Intinya ini kan soal linear programming, ubah permasalahan jadi bentuk dual
// Udah lupa sih gmn cara ubah jadi ke versi dualnya :v
// Intinya targetnya dibalik dari minimum jadi maksimum dan constraint sama variablenya juga dituker mungkin(?)

// 0 = 0, 1 = x+y, 2 = y
inline ST merge(ST le, ST ri){
	ret = {ard(3){-INF,-INF,-INF}, ard(3){-INF,-INF,-INF}, ard(3){-INF,-INF,-INF}};
	rep(i,0,2)rep(j,0,2)if(le[i][j] != -INF){
		rep(k,0,2)if(j+k<=2)rep(o,0,2)if(ri[k][o] != -INF)
			ret[i][o] = max(ret[i][o], le[i][j] + ri[k][o]);
	}
	return ret;
}

void build(int id,int le,int ri){
	if(le==ri){
		tree[id] = {ard(3){0.,-INF,-INF}, ard(3){-INF,z[le]*x,-INF}, ard(3){-INF,-INF,z[le]*y}};
		return;
	}
	int mid = le+ri>>1;
	build(lc,le,mid), build(rc,mid+1,ri);
	tree[id] = merge(tree[lc], tree[rc]);
	return;
}

void upd(int id,int le,int ri){
	if(le==ri){
		tree[id] = {ard(3){0.,-INF,-INF}, ard(3){-INF,z[le]*x,-INF}, ard(3){-INF,-INF,z[le]*y}};
		return;
	}
	int mid = le+ri>>1;
	if(a<=mid)upd(lc,le,mid);
	else upd(rc,mid+1,ri);
	tree[id] = merge(tree[lc], tree[rc]);
	return;
}

ST que(int id,int le,int ri){
	if(le>=a && ri<=b)return tree[id];
	int mid = le+ri>>1;
	if(a<=mid && mid+1<=b)return merge(que(lc,le,mid), que(rc,mid+1,ri));
	if(a<=mid)return que(lc,le,mid);
	return que(rc,mid+1,ri);
}

int main(){
	cout<<fixed<<setprecision(10);
//	freopen("input.txt", "r", stdin);
//	freopen("output.txt","w",stdout);
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	cin>>n>>q;
	cin>>x>>y;
	if(x>y)swap(x, y);
	x = 1./(x+y), y = 1./y;
	
	rep(i,1,n)cin>>z[i];
	build(1,1,n);
	
	while(q--){
		cin>>op>>a>>b;
		if(op==1){
			z[a] = b;
			upd(1,1,n);
		}
		else {
			ret = que(1,1,n);
			ans = -INF;
			rep(i,0,2)rep(j,0,2)ans = max(ans, ret[i][j]);
			cout<<ans<<endl;
		}
	}
	return 0;
}