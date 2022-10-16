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
//#define endl '\n'
const int MAX = 1e5+5;
const ll MOD = 1000000007;
const ll MOD2 = 2010405347;
const ll INF = 2e18;
const int dr[]={1,0,-1,0,1,1,-1,-1,0};
const int dc[]={0,1,0,-1,1,-1,1,-1,0};
const double pi = acos(-1);
const double EPS = 1e-9;
const int block = 5;
inline ll pw(ll x,ll y,ll md){ll ret=1;x%=md;while(y){if(y&1)ret=ret*x%md;x=x*x%md,y>>=1;}return ret;}
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

class DynamicPersistentSegtree{
public:
	using RG = int; // Tree Range Size
	using TD = int; // Data type inside segtree
	RG N;
	int ptr;
	struct P{
		TD val=0;
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
	
	inline int merge(TD &le, TD &ri){
		return le + ri;
	}
	
	int update(int id, RG le, RG ri, RG a, int val){
		id = copyNode(id);
		if(le == ri){
			node[id].val += val;
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
		if(le > b || ri < a || !id) return 0;
		if(le >= a && ri <= b) {
			return node[id].val;
		}
		RG mid = (le + ri) / 2;
		return query(node[id].lc, le, mid, a, b)
        		+ query(node[id].rc, mid + 1, ri, a, b);
	}
	
	DynamicPersistentSegtree(RG _N, int Q) : N(_N), ptr(0) {
		node.reserve((log2(_N)+1) * Q);
		newNode();
		newNode();
		root.push_back(1);
	}
	
	int upd(int a, int val, int head=-1){
		if(head==-1)head = root.size()-1;
		root.push_back(update(root[head], 1, N, a, val));
		return root.size()-1;
	}
	
	TD que(int id, int a, int b){
		return query(root[id], 1, N, a, b);
	}
}tree(1e9, 200000);

class PersistentSegtree{
public:
	using RG = int; // Tree Range Size
	using TD = int; // Data type inside segtree
	RG N;
	int ptr;
	struct P{
		TD val=0;
		int lc=0, rc=0;
	};
	vector<P> node;
	vector<int> root;
	int newNode() {
		node.emplace_back();
		return ptr++;
	}
	int copyNode(int idx) {
		node.push_back(node[idx]);
		return ptr++;
	}
	
	int update(int id, RG le, RG ri, RG a, int val){
		id = copyNode(id);
		if(le == ri){
			node[id].val = val;
			return id;
		}
		RG mid = (le + ri) / 2;
		if(a <= mid){
			node[id].lc = update(node[id].lc, le, mid, a, val);
		}
		else {
			node[id].rc = update(node[id].rc, mid+1, ri, a, val);
		}
		return id;
	}
	
	TD query(int id, RG le, RG ri, RG a){
		if(!id) return 0; //out of bound
		if(le == ri) return node[id].val;
		RG mid = (le + ri) / 2;
		if(a <= mid) return query(node[id].lc, le, mid, a);
		return query(node[id].rc, mid + 1, ri, a);
	}
	
	PersistentSegtree(RG _N, int Q) : N(_N), ptr(0) {
		node.reserve((log2(_N)+1) * Q);
		newNode();
		newNode();
		root.push_back(1);
	}
	
	int upd(int a, int val, int head=-1){
		if(head==-1)head = root.size()-1;
		root.push_back(update(root[head], 1, N, a, val));
		return root.size()-1;
	}
	
	TD que(int id, int a){
		return query(root[id], 1, N, a);
	}
}isi(1e5, 200000);

int q, val, res, id, nw, pos, his[MAX];
map<string,int> hs;
string op, s;

int main(){
//	cout<<fixed<<setprecision(10);
//	freopen("input.txt", "r", stdin);
//	freopen("output.txt","w",stdout);
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	cin>>q;
	rep(i,1,q){
		cin>>op;
		if(op=="set"){
			cin>>s>>val;
			if(!hs.count(s))hs[s] = ++id;
			pos = hs[s];
			res = isi.que(nw, pos);
			if(res != val){
				if(res){
					isi.root.pb(isi.root[nw]); // dummy
					nw = tree.upd(res, -1, nw);
				}
				isi.upd(pos, val, nw);
				nw = tree.upd(val, 1, nw);
			}
		}
		else if(op=="remove"){
			cin>>s;
			if(!hs.count(s))hs[s] = ++id;
			pos = hs[s];
			res = isi.que(nw, pos);
			if(res){
				isi.upd(pos, 0, nw);
				nw = tree.upd(res, -1, nw);
			}
		}
		else if(op=="query"){
			cin>>s;
			if(!hs.count(s))hs[s] = ++id;
			pos = hs[s];
			res = isi.que(nw, pos);
			if(!res){
				cout<<"-1"<<endl;
			}
			else {
				res = tree.que(nw, 1, res-1);
				cout<<res<<endl;
			}
		}
		else if(op=="undo"){
			cin>>val;
			nw = his[i-val-1];
		}
		his[i] = nw;
	}
	return 0;
}