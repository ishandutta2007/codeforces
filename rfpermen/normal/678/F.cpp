#include<bits/stdc++.h>
 
#pragma GCC optimize("O3")
#pragma GCC target("tune=native")
#pragma GCC optimize("unroll-loops")
 
using namespace std;
#define ll long long
#define ull unsigned long long
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
#define PQ(T) priority_queue<T>
#define PQr(T) priority_queue<T, vector<T>, greater<T>>
#define permute(x) while(next_permutation(all(x)))
#define vi vector<int>
#define vii vector<pii>
#define vl vector<ll>
#define vll vector<pll>
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
//const int MAX = 2e5+5;
const ll MOD = 998244353;
const ll MOD2 = 2010405347;
//const ll INF = 2e18;
const int dr[]={1,0,-1,0,1,1,-1,-1,0};
const int dc[]={0,1,0,-1,1,-1,1,-1,0};
const double pi = acos(-1);
const double EPS = 1e-9;
inline ll pw(ll x,ll y,ll md=MOD){ll ret=1;x%=md;while(y){if(y&1)ret=ret*x%md;x=x*x%md,y>>=1;}return ret;}
mt19937_64 rng(chrono::steady_clock::now().time_since_epoch().count());

// max li-chao tree
// works for the range [0, MAX - 1]
// if min li-chao tree:
// replace every call to max() with min() and every > with <
// also replace -INF with INF

struct Func {
  ll m, c;
  ll operator()(ll x) {
    return x * m + c;
  }
};

const int MAX = 1e9 + 1;
const ll INF = 1e18;
const Func NIL = {0, -INF};

struct Node {
  Func f;
  Node* lc;
  Node* rc;

  Node() : f(NIL), lc(nullptr), rc(nullptr) {}
  Node(const Node& n) : f(n.f), lc(nullptr), rc(nullptr) {}
};

Node* root_pos = new Node, *root_neg = new Node;

void insert(Func f, Node* cur, int l = 0, int r = MAX - 1) {
  int m = l + (r - l) / 2;
  bool left = f(l) > cur->f(l);
  bool mid = f(m) > cur->f(m);
  if(mid)
    swap(f, cur->f);
  if(l != r) {
    if(left != mid) {
      if(!cur->lc)
        cur->lc = new Node(*cur);
      insert(f, cur->lc, l, m);
    } else {
      if(!cur->rc)
        cur->rc = new Node(*cur);
      insert(f, cur->rc, m + 1, r);
    }
  }
}

ll query(ll x, Node* cur, int l = 0, int r = MAX - 1) {
  if(!cur)
    return -INF;
  if(l == r)
    return cur->f(x);
  int m = l + (r - l) / 2;
  if(x <= m)
    return max(cur->f(x), query(x, cur->lc, l, m));
  else
    return max(cur->f(x), query(x, cur->rc, m + 1, r));
}

void clear(Node* nw){
	if(nw->lc)clear(nw->lc);
	if(nw->rc)clear(nw->rc);
	free(nw);
}

const int MAX2 = 3e5 + 5;
const int block = 2500;

int n,op[MAX2],a[MAX2],b[MAX2],x,y;
set<pii> fix,nw;
ll ans;

int main(){
//	cout<<fixed<<setprecision(2);
//	freopen("input.txt", "r", stdin);
//	freopen("output.txt","w",stdout);
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	
//	insert({-10,-10}, root_neg);
//	insert({-10,10}, root_neg);
//	ll ans = query(-10, root_neg);
//	cout<<ans<<endl;
	
	cin>>n;
	rep(i,1,n){
		cin>>op[i];
		if(op[i]==1)cin>>a[i]>>b[i];
		else cin>>a[i];
	}
	int lp;
	rep(i,1,n){
		if(i%block==1){
			lp = min(n, (i/block + 1)*block);
			clear(root_pos);
			clear(root_neg);
			root_pos = new Node;
			root_neg = new Node;
			for(auto j:nw)fix.insert(j);
			nw.clear();
			rep(j,i,lp){
				if(op[j]==2){
					if(a[j]<i){
						fix.erase({a[a[j]], b[a[j]]});
						nw.insert({a[a[j]], b[a[j]]});
					}
				}
			}
			x = y = 0;
			for(auto j:fix){
				if(j.fi<0)insert({-j.fi,j.se}, root_neg), ++x;
				else insert({j.fi,j.se}, root_pos), ++y;
			}
		}
		if(op[i]==1)nw.insert({a[i], b[i]});
		else if(op[i]==2)nw.erase({a[a[i]], b[a[i]]});
		else {
			ans = -2e18;
			for(auto j:nw)ans = max(ans, (ll)a[i]*j.fi + j.se);
			if(x)ans = max(ans, query(-a[i], root_neg));
			if(y)ans = max(ans, query(a[i], root_pos));
			if(ans==-2e18)cout<<"EMPTY SET\n";
			else cout<<ans<<endl;
		}
	}
	return 0;
}