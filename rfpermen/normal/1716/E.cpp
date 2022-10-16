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
const int MAX = (1<<19)+5;
const ll MOD = 998244353;
const ll MOD2 = 2010405347;
const ll INF = 2e18;
const int dr[]={1,0,-1,0,1,1,-1,-1,0};
const int dc[]={0,1,0,-1,1,-1,1,-1,0};
const double pi = acos(-1);
const double EPS = 1e-9;
const int block = 8;
inline ll pw(ll x,ll y,ll md=MOD){ll ret=1;x%=md;while(y){if(y&1)ret=ret*x%md;x=x*x%md,y>>=1;}return ret;}
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

int n,k,nw,lp,x[MAX],tmp,val,mini,idx;
arll(4) pre[1<<block][1<<(19-block)],ret;
ll mx[1<<block],ans;
struct segtree{
	arll(4) val;
	int lef, rig;
}tree[MAX];

// mx, sum, mx_le, mx_ri, lc, rc

inline arll(4) merge(const arll(4)& le, const arll(4)& ri){
	ret[0] = max(max(le[0], ri[0]), le[3]+ri[2]);
	ret[1] = le[1]+ri[1];
	ret[2] = max(le[2], le[1]+ri[2]);
	ret[3] = max(ri[3], ri[1]+le[3]);
	return ret;
}

void get(int id,int sz){
	if(sz==val){
		swap(tree[id].lef, tree[id].rig);
	}
	else {
		get(tree[id].lef, sz-1);
		get(tree[id].rig, sz-1);
	}
	if(sz<=mini)tree[id].val = merge(tree[tree[id].lef].val, tree[tree[id].rig].val);
	if(sz==mini)pre[nw][idx++] = ret, mx[nw] = max(mx[nw], ret[0]);
	return;
}

void build(int id,int le,int ri,int sz){
	if(le==ri){
		tree[id].val = {max(0,x[le]), x[le], max(0,x[le]), max(0,x[le])};
		return;
	}
	int mid = le+ri>>1;
	build(lc, le, mid, sz-1);
	build(rc, mid+1, ri, sz-1);
	tree[id].val = merge(tree[lc].val, tree[rc].val);
	if(sz==mini)pre[nw][idx++] = ret, mx[nw] = max(mx[nw], ret[0]);
	tree[id].lef = lc;
	tree[id].rig = rc;
	return;
}

int main(){
//	cout<<fixed<<setprecision(4);
//	freopen("input.txt", "r", stdin);
//	freopen("output.txt","w",stdout);
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	cin>>k;
//	k = 18;
	mini = min(block, k);
	n = 1<<k;
	rep(i,1,n){
		cin>>x[i];
//		val = rng()%1000000000;
//		if(rng()%100<50)val*= -1;
//		x[i] = val;
	}
	build(1,1,n,k);
	lp = 1<<mini;
	For(i,1,lp){
		tmp = i, val = 1;
		while((tmp&1)==0)tmp>>= 1, ++val;
		nw^= 1<<(val-1);
		idx = 0;
		get(1,k);
	}
	n = 1<<(k-mini);
	For(i,0,n)x[i] = i;
	nw = 0;
	int q=0;
	cin>>q;
	ll sm;
	int pos;
	while(q--){
		cin>>val;
		if(val<mini)nw^= 1<<val;
		if(val>=mini){
			val = 1<<(val-mini);
			For(i,0,n)if((i&val)==0){
				tmp = x[i];
				x[i] = x[i^val];
				x[i^val] = tmp;
			}
		}
		ans = mx[nw], sm = 0;
		For(i,0,n){
			pos = x[i];
//			out(pos, pre[nw][pos]);
			ans = max(ans, sm+pre[nw][pos][2]);
			sm = max(sm+pre[nw][pos][1], pre[nw][pos][3]);
		}
		cout<<ans<<endl;
	}
	return 0;
}