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
const ll MOD = 1000000007;
const ll MOD2 = 2010405347;
const ll INF = 2e18;
const int dr[]={1,0,-1,0,1,1,-1,-1,0};
const int dc[]={0,1,0,-1,1,-1,1,-1,0};
const double pi = acos(-1);
const double EPS = 1e-9;
const int block = 444;
inline ll pw(ll x,ll y,ll md=MOD){ll ret=1;x%=md;while(y){if(y&1)ret=ret*x%md;x=x*x%md,y>>=1;}return ret;}
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

int n,q,a,b;
double x[MAX],tree[1<<18],res1,res2,val,p;
pair<double,double> lz[1<<18];

void build(int id,int le,int ri){
	lz[id] = {1., 0.};
	if(le==ri){
		tree[id] = x[le];
		return;
	}
	int mid = le+ri>>1;
	build(lc,le,mid), build(rc,mid+1,ri);
	tree[id] = tree[lc] + tree[rc];
	return;
}

inline void f(int id,int le,int ri){
	tree[id] = (tree[id]/(ri-le+1)*lz[id].fi + lz[id].se)*(ri-le+1);
	if(le!=ri){
		lz[lc] = {lz[lc].fi*lz[id].fi, lz[lc].se*lz[id].fi + lz[id].se};
		lz[rc] = {lz[rc].fi*lz[id].fi, lz[rc].se*lz[id].fi + lz[id].se};
	}
	lz[id] = {1.,0.};
	return;
}

void upd(int id,int le,int ri){
	if(lz[id].fi!=1.)f(id,le,ri);
	if(le>b || ri<a)return;
	if(le>=a && ri<=b){
		lz[id] = {p, val};
		f(id,le,ri);
		return;
	}
	int mid = le+ri>>1;
	upd(lc,le,mid), upd(rc,mid+1,ri);
	tree[id] = tree[lc] + tree[rc];
	return;
}

double que(int id,int le,int ri){
	if(le>b || ri<a)return 0.;
	if(lz[id].fi!=1.)f(id,le,ri);
	if(le>=a && ri<=b)return tree[id];
	int mid = le+ri>>1;
	return que(lc,le,mid) + que(rc,mid+1,ri);
}

int main(){
	cout<<fixed<<setprecision(6);
//	freopen("input.txt", "r", stdin);
//	freopen("output.txt","w",stdout);
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	int l1,l2,r1,r2,op;
	cin>>n>>q;
	rep(i,1,n)cin>>x[i];
	build(1,1,n);
	while(q--){
		cin>>op;
		if(op==1){
			cin>>l1>>r1>>l2>>r2;
			a = l1, b = r1;
			res1 = que(1,1,n)/(b-a+1);
			a = l2, b = r2;
			res2 = que(1,1,n)/(b-a+1);
			
			a = l1, b = r1;
			p = 1. - 1./(b-a+1);
			val = res2 * (1.-p);
			upd(1,1,n);
			
			a = l2, b = r2;
			p = 1. - 1./(b-a+1);
			val = res1 * (1.-p);
			upd(1,1,n);
		}
		else {
			cin>>a>>b;
			cout<<que(1,1,n)<<endl;
		}
	}
	return 0;
}