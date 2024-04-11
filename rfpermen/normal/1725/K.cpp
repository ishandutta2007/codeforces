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

struct DynamicSegtree{
	vi v;
	int le=0,ri=0;
}tree[MAX*29];

int n,q,x[MAX],ls[MAX],a,b,op,wk,ix=1,val[MAX*2],p[MAX*2],N=1e9;
set<pii> s;
vii del;

void upd(int id,int le,int ri){
	if(le>=a && ri<=b){
		tree[id].v.pb(wk);
		return;
	}
	int mid = le+ri>>1;
	if(!(b<le || a>mid)){
		if(!tree[id].le)tree[id].le = ++ix;
		upd(tree[id].le,le,mid);
	}
	if(!(b<mid+1 || a>ri)){
		if(!tree[id].ri)tree[id].ri = ++ix;
		upd(tree[id].ri,mid+1,ri);
	}
	return;
}

int que(int id,int le,int ri){
	int ret = MOD;
	if(le<=a && a<=ri && tree[id].v.size() && tree[id].v.back()>wk){
		ret = *(upper_bound(all(tree[id].v),wk));
	}
	if(le==ri)return ret;
	int mid = le+ri>>1;
	if(a<=mid){
		if(tree[id].le)ret = min(ret, que(tree[id].le,le,mid));
	}
	else {
		if(tree[id].ri)ret = min(ret, que(tree[id].ri,mid+1,ri));
	}
	return ret;
}

int par(int z){
	if(p[z]==z)return z;
	return p[z] = par(p[z]);
}

int main(){
//	cout<<fixed<<setprecision(0);
//	freopen("input.txt", "r", stdin);
//	freopen("output.txt","w",stdout);
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	cin>>n;
	rep(i,1,n)cin>>x[i];
	cin>>q;
	auto it = s.begin();
	int A,B;
	rep(i,1,q){
		cin>>op;
		if(op==1){
			cin>>a>>b;
			x[a] = b;
			ls[a] = i;
		}
		else if(op==2){
			cin>>a;
			wk = ls[a];
			a = x[a];
			b = que(1,1,N)*2;
			if(b>MOD)cout<<a<<endl;
			else {
				A = a-val[b], B = val[b+1]-a;
				cout<<val[par(A<B ? b : b+1)]<<endl;
			}
		}
		else {
			cin>>a>>b;
			--a, ++b;
			wk = i;
			upd(1,1,N);
			it = s.lower_bound({a,0});
			del.clear();
			while(it!=s.end() && (*it).fi<=b){
				del.pb(*it);
				++it;
			}
			for(auto j:del){
				s.erase(j);
				A = j.fi-a, B = b-j.fi;
				p[j.se] = A<B ? i*2 : i*2+1;
			}
			s.insert({a,i*2});
			s.insert({b,i*2+1});
			p[i*2] = i*2;
			p[i*2+1] = i*2+1;
			val[i*2] = a;
			val[i*2+1] = b;
		}
	}
//	db(ix);
	return 0;
}