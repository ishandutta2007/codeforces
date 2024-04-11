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
const int MAX = 1e5+5;
const ll MOD = 998244353;
const ll MOD2 = 2010405347;
const ll INF = 2e18;
const int dr[]={1,0,-1,0,1,1,-1,-1,0};
const int dc[]={0,1,0,-1,1,-1,1,-1,0};
const double pi = acos(-1);
const double EPS = 1e-9;
const int block = 400;
inline ll pw(ll x,ll y,ll md=MOD){ll ret=1;x%=md;while(y){if(y&1)ret=ret*x%md;x=x*x%md,y>>=1;}return ret;}
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

ll ret,tree[1<<18],lz[1<<18],rt;
int n,q,a,b,x[MAX],en[MAX],st[MAX],id,op,val,dep[MAX],sp[18][MAX];
vi v[MAX];

void dfs(int nw,int par){
	st[nw] = ++id;
	dep[id] = dep[st[par]]+1;
	sp[0][id] = st[par];
	for(int i:v[nw])if(i!=par){
		dfs(i, nw);
	}
	en[st[nw]] = id;
	return;
}

inline int lca(int x,int y){
	if(dep[x]<dep[y])swap(x,y);
	rap(i,16,0)if(dep[x]-(1<<i) >= dep[y])x = sp[i][x];
	if(x==y)return x;
	rap(i,16,0){
		if(sp[i][x]!=sp[i][y]){
			x = sp[i][x];
			y = sp[i][y];
		}
	}
	return sp[0][x];
}

inline void f(int id,int le,int ri){
	tree[id]+= lz[id]*(ri-le+1);
	if(le!=ri){
		lz[lc]+= lz[id];
		lz[rc]+= lz[id];
	}
	lz[id] = 0;
	return;
}

void upd(int id,int le,int ri){
	if(lz[id])f(id,le,ri);
	if(le>b || ri<a)return;
	if(le>=a && ri<=b){
		lz[id] = val;
		f(id,le,ri);
		return;
	}
	int mid = le+ri>>1;
	upd(lc,le,mid), upd(rc,mid+1,ri);
	tree[id] = tree[lc] + tree[rc];
	return;
}

ll que(int id,int le,int ri){
	if(le>b || ri<a)return 0;
	if(lz[id])f(id,le,ri);
	if(le>=a && ri<=b)return tree[id];
	int mid = le+ri>>1;
	return que(lc,le,mid) + que(rc,mid+1,ri);
}

int main(){
//	cout<<fixed<<setprecision(6);
//	freopen("input.txt", "r", stdin);
//	freopen("output.txt","w",stdout);
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	cin>>n>>q;
	rep(i,1,n)cin>>x[i];
	rep(i,2,n){
		cin>>a>>b;
		v[a].pb(b);
		v[b].pb(a);
	}
	rt = 1;
	dep[1] = 1;
	dfs(1,0);
	rep(i,1,16)rep(j,1,n)sp[i][j] = sp[i-1][sp[i-1][j]];
	rep(i,1,n)a = b = st[i], val = x[i], upd(1,1,n);
//	rep(i,1,n)cout<<st[i]<<" "; cout<<endl;
	int c,d,e,dis;
	while(q--){
		cin>>op;
		if(op==1)cin>>rt, rt = st[rt];
		else if(op==2){
			cin>>a>>b>>val;
			a = st[a], b = st[b];
			if(dep[a]<dep[b])swap(a,b); //jadi a sekarang lebih dibawah
			c = lca(a,b);
//			db(c);
			if(c<=rt && rt<=en[c]){ // root ada di dalam subtree lca(a,b)
				d = lca(a, rt);
				e = lca(b, rt);
				if(d==rt || e==rt){ // root ada di jalur dari a ke b
					// update semua elemen di tree
					a = 1, b = n;
					upd(1,1,n);
				}
				else {
					c = max(d, e); // ini lca kalau di root rt!=1
					// lca nya itu pasti ada di jalur dari a ke b juga
					
					// update semua elemen di tree
					a = 1, b = n;
					upd(1,1,n);
					
					// exclude yang di subtree sebelum lca
					dis = dep[rt] - dep[c] - 1;
					a = rt;
					rap(i,16,0)if(dis&(1<<i))a = sp[i][a];
					b = en[a];
					val = -val;
					upd(1,1,n);
				}
			}
			else {
				a = c, b = en[c];
				upd(1,1,n);
			}
		}
		else {
			cin>>a;
			a = st[a];
			if(a == rt){
				cout<<tree[1]<<endl;
			}
			else if(lca(a, rt) == a){ // root ada di subtree a
				dis = dep[rt] - dep[a] - 1;
				a = rt;
				rap(i,16,0)if(dis&(1<<i))a = sp[i][a];
				b = en[a];
				cout<<tree[1] - que(1,1,n)<<endl;
			}
			else {
				b = en[a];
				cout<<que(1,1,n)<<endl;
			}
		}
	}
	return 0;
}