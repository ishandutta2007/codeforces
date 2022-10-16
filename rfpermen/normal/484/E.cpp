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

class PersistentSegtree{
public:
	using RG = int; // Tree Range Size
	struct TD{ // Data type inside segtree
		int le=0, ri=0, mx=0, len=0;
	};
	RG N;
	TD ret, NIL;
	int ptr;
	struct P{
		TD val;
		int lc=0, rc=0;
	};
	vector<P> node;
	vector<int> root;
	int newNode() {
		node.emplace_back();
		return ptr++;
	}
	int copyNode(int idx) {
		node.emplace_back(node[idx]);
		return ptr++;
	}
	
	inline TD merge(TD le, TD ri){
		ret.mx = max(max(le.mx, ri.mx), le.ri + ri.le);
		ret.len = le.len + ri.len;
		ret.le = (le.le == le.len) ? le.le + ri.le : le.le;
		ret.ri = (ri.ri == ri.len) ? ri.ri + le.ri : ri.ri;
		return ret;
	}
	
	int update(int id, RG le, RG ri, RG a, int val){
		id = copyNode(id);
		if(le == ri){
			node[id].val.le = val;
			node[id].val.ri = val;
			node[id].val.mx = val;
			node[id].val.len= 1;
			return id;
		}
		RG mid = (le + ri) / 2;
		if(a <= mid){
			node[id].lc = update(node[id].lc, le, mid, a, val);
		}
		else {
			node[id].rc = update(node[id].rc, mid+1, ri, a, val);
		}
		node[id].val = merge(node[node[id].lc].val, node[node[id].rc].val);
		return id;
	}
	
	TD query(int id, RG le, RG ri, RG a, RG b){
		if(!id) return NIL;
		if(le >= a && ri <= b) {
			return node[id].val;
		}
		RG mid = (le + ri) / 2;
		if(a<=mid && mid+1<=b)
			return merge(query(node[id].lc, le, mid, a, b), query(node[id].rc, mid + 1, ri, a, b));
		if(a<=mid)return query(node[id].lc, le, mid, a, b);
		return query(node[id].rc, mid + 1, ri, a, b);
	}
	
	PersistentSegtree(RG _N, int _Q) : N(_N), ptr(0) {
		node.reserve((log2(_N)+2) * (_Q + 5));
		root.reserve(_Q + 5);
		newNode();
		root.push_back(0);
	}
	
	int upd(int a, int val, int head=-1){
		assert(head <= (int)root.size());
		if(head==-1)head = root.size()-1;
		root.push_back(update(root[head], 1, N, a, val));
		return root.size()-1;
	}
	
	TD que(int id, int a, int b){
		return query(root[id], 1, N, a, b);
	}
};

int n,q,le,ri,mid,res,tmp,l,r,w;
pii x[MAX];

int main(){
//	cout<<fixed<<setprecision(10);
//	freopen("input.txt", "r", stdin);
//	freopen("output.txt","w",stdout);
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	cin>>n;
	PersistentSegtree tree(n, n*2);
	rep(i,1,n)tree.upd(i, 0); // build PST (soalnya walaupun kosong data len nya masih penting juga)
	tmp = tree.root.back();
	tree.root.clear();
	tree.root.pb(tmp);
	
	rep(i,1,n)cin>>x[i].fi, x[i].se = i;
	revsort(x+1,x+1+n);
	rep(i,1,n)tree.upd(x[i].se, 1);
	
	cin>>q;
	while(q--){
		cin>>l>>r>>w;
		le = 1, ri = n, res = -1;
		while(le<=ri){
			mid = le+ri>>1;
			if(tree.que(mid, l, r).mx >= w)res = x[mid].fi, ri = mid-1;
			else le = mid+1;
		}
		assert(res!=-1);
		cout<<res<<endl;
	}
	return 0;
}