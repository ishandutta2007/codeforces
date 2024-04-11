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
const int MAX = 4e5+5;
const ll MOD = 1000000007;
const ll MOD2 = 2010405347;
const ll INF = 2e18;
const int dr[]={1,0,0,-1};
const int dc[]={0,-1,1,0};
const double pi = acos(-1);
const double EPS = 1e-9;
const int block = 8;
inline ll pw(ll x,ll y,ll md=MOD){ll ret=1;x%=md;while(y){if(y&1)ret=ret*x%md;x=x*x%md,y>>=1;}return ret;}
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

const int K = 26;
struct Vertex {
  int next[K];
  bool leaf = 0;
  int p = -1, ans = 0;
  char pch;
  int link = -1, mlink = -1;
  //magic link, is the link to find the nearest leaf
  int go[K];
  Vertex(int p = -1, char ch = '$') : p(p), pch(ch) {
    fill(begin(next), end(next), -1);
    fill(begin(go), end(go), -1);
  }
};
vector<Vertex> t;
int add_string(string const& s) {
  int v = 0;
  for(char ch : s) {
    int c = ch - 'a';
    if(t[v].next[c] == -1) {
      t[v].next[c] = t.size();
      t.emplace_back(v, ch);
    }
    v = t[v].next[c];
  }
  t[v].leaf = 1;
  return v;
}
int go(int v, char ch);
int get_link(int v) {
  if(t[v].link == -1) {
    if(v == 0 || t[v].p == 0)
      t[v].link = 0;
    else
      t[v].link = go(get_link(t[v].p), t[v].pch);
  }
  return t[v].link;
}
int get_mlink(int v) {
  if(t[v].mlink == -1) {
    if(v == 0 || t[v].p == 0)
      t[v].mlink = 0;
    else {
      t[v].mlink = go(get_link(t[v].p), t[v].pch);
      if(t[v].mlink && !t[t[v].mlink].leaf) {
        if(t[t[v].mlink].mlink == -1)
          get_mlink(t[v].mlink);
        t[v].mlink = t[t[v].mlink].mlink;
      }
    }
  }
  return t[v].mlink;
}
int go(int v, char ch) {
  int c = ch - 'a';
  if(t[v].go[c] == -1) {
    if(t[v].next[c] != -1)
      t[v].go[c] = t[v].next[c];
    else
      t[v].go[c] = v == 0 ? 0 : go(get_link(v), ch);
  }
  return t[v].go[c];
}
//t.pb(Vertex());

int n,m,op,a,pos[MAX],ans[MAX],res[MAX];
char c;
vector<pair<int,char>> u[MAX];
vi v[MAX],qu[MAX];
string s;

void dfs(int nw,int node){
	res[nw] = node;
	for(auto i:u[nw])dfs(i.fi, go(node, i.se));
	return;
}

int st[MAX],en[MAX],id,tree[1<<20];

void construct(int nw){
	st[nw] = ++id;
	for(int i:v[nw])construct(i);
	en[nw] = id;
	return;
}

void upd(int id,int le,int ri,int a,int val){
	if(le==ri){
		tree[id]+= val;
		return;
	}
	int mid = le+ri>>1;
	if(a<=mid)upd(lc,le,mid,a,val);
	else upd(rc,mid+1,ri,a,val);
	tree[id] = tree[lc] + tree[rc];
	return;
}

int que(int id,int le,int ri,int a,int b){
	if(le>b || ri<a)return 0;
	if(le>=a && ri<=b)return tree[id];
	int mid = le+ri>>1;
	return que(lc,le,mid,a,b) + que(rc,mid+1,ri,a,b);
}

int N;
void solve(int nw){
	for(auto i:qu[nw]){
		ans[i] = que(1,1,N,st[pos[i]],en[pos[i]]);
	}
	for(auto i:u[nw]){
		upd(1,1,N,st[res[i.fi]],1);
		solve(i.fi);
		upd(1,1,N,st[res[i.fi]],-1);
	}
}

int main(){
//	cout<<fixed<<setprecision(10);
//	freopen("input.txt", "r", stdin);
//	freopen("output.txt","w",stdout);
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	t.pb(Vertex());
	cin>>n;
	rep(i,1,n){
		cin>>op;
		if(op==1)a = 0;
		else cin>>a;
		cin>>c;
		u[a].pb({i,c});
	}
	cin>>m;
	rep(i,1,m){
		cin>>a>>s;
		qu[a].pb(i);
		pos[i] = add_string(s);
	}
	dfs(0,0);
	N = t.size();
	For(i,1,N)v[get_link(i)].pb(i);
	construct(0);
	solve(0);
	rep(i,1,m)cout<<ans[i]<<endl;
	return 0;
}