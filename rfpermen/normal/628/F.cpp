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
const int MAX = 1e4+5;
const ll MOD = 998244353;
const ll MOD2 = 2010405347;
const ll INF = 2e18;
const int dr[]={1,0,0,-1,1,1,-1,-1};
const int dc[]={0,-1,1,0,1,-1,1,-1};
const double pi = acos(-1);
const double EPS = 1e-9;
const int block = 8;
inline ll pw(ll x,ll y,ll md=MOD){ll ret=1;x%=md;while(y){if(y&1)ret=ret*x%md;x=x*x%md,y>>=1;}return ret;}
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

struct Dinic {
  struct Edge {
    int v;
    int cap, flow;
    Edge(int _v, int _cap): v(_v), cap(_cap), flow(0) {}
  };

  int n;
  int lim;
  vector<vector<int>> gr;
  vector<Edge> e;
  vector<int> idx, lv;

  bool has_path(int s, int t) {
    queue<int> q;
    q.push(s);
    lv.assign(n, -1);
    lv[s] = 0;
    while(!q.empty()) {
      int c = q.front();
      q.pop();
      if(c == t)
        break;
      for(auto& i : gr[c]) {
        int cur_flow = e[i].cap - e[i].flow;
        if(lv[e[i].v] == -1 && cur_flow >= lim) {
          lv[e[i].v] = lv[c] + 1;
          q.push(e[i].v);
        }
      }
    }
    return lv[t] != -1;
  }

  int get_flow(int s, int t, int left) {
    if(!left || s == t)
      return left;
    while(idx[s] < (int) gr[s].size()) {
      int i = gr[s][idx[s]];
      if(lv[e[i].v] == lv[s] + 1) {
        int add = get_flow(e[i].v, t, min(left, e[i].cap - e[i].flow));
        if(add) {
          e[i].flow += add;
          e[i ^ 1].flow -= add;
          return add;
        }
      }
      ++idx[s];
    }
    return 0;
  }

  Dinic(int vertices, bool scaling = 0) : // toggle scaling here
    n(vertices), lim(scaling ? 1 << 30 : 1), gr(n) {}

  void add_edge(int from, int to, int cap, bool directed = 1) {
    gr[from].push_back(e.size());
    e.emplace_back(to, cap);
    gr[to].push_back(e.size());
    e.emplace_back(from, directed ? 0 : cap);
  }

  int get_max_flow(int s, int t) { // caint this
    int res = 0;
    while(lim) {  // scaling
      while(has_path(s, t)) {
        idx.assign(n, 0);
        while(int add = get_flow(s, t, 1e9))
          res += add;
      }
      lim >>= 1;
    }
    return res;
  }
};

int n,k,q,ls,val,rem[5],a,b,ttl;
vii z;
vector<ari(3)> x;
bool st[MAX];

int main(){
//	cout<<fixed<<setprecision(10);
//	freopen("input.txt", "r", stdin);
//	freopen("output.txt","w",stdout);
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	cin>>k>>n>>q;
	rep(i,1,q){
		cin>>ls>>val;
		z.pb({ls, val});
	}
	rep(i,0,4)rem[i] = k/5;
	z.pb({n, k});
	sort(all(z));
	ls = val = 0;
	for(auto i:z){
		a = i.fi-ls, b = i.se-val;
		if(b<0 || a<b)return cout<<"unfair\n",0;
		if(b==0 || a==b){
			rep(j,ls+1,i.fi){
				rem[j%5]-= a==b;
				st[j] = 1;
			}
			if(a==b)ttl+= b;
		}
		else {
			x.pb({ls+1,i.fi,b});
		}
		ls = i.fi, val = i.se;
	}
	rep(i,0,4)if(rem[i]<0)return cout<<"unfair\n",0;
	Dinic g(n+10+x.size());
	rep(i,1,5){
		g.add_edge(0,n+i,rem[i%5]);
		rip(j,i,n,5)if(!st[j])g.add_edge(n+i,j,1);
	}
	int nw = n+5, en = n+x.size()+7;
	for(auto i:x){
		++nw;
		g.add_edge(nw,en,i[2]);
		rep(j,i[0],i[1])g.add_edge(j,nw,1);
	}
	ttl+= g.get_max_flow(0,en);
	cout<<(ttl==k ? "fair" : "unfair")<<endl;
	return 0;
}