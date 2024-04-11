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
const int MAX = 1e3+5;
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

int n,x[MAX],mx,st,gd,hit;
vii ans,bt,z;

inline void upd(int le,int ri,vii &z){
	++hit;
	z.pb({x[le], x[le]});
	if(le+1<ri)z.pb({x[le+1], x[ri-1]});
	if(le<ri)z.pb({x[ri], x[ri]});
	return;
}

inline bool cek(){
	int ls = -1;
	for(auto i:z){
		if(i.se<i.fi)return false;
		if(i.fi<ls)return false;
		ls = i.se;
	}
	return true;
}

inline void rev(int le,int ri){
	reverse(z.begin()+le, z.begin()+ri+1);
	rep(i,le,ri)swap(z[i].fi, z[i].se);
	return;
}

bool bf(int turn){
	if(turn==0){
		if(cek()){
			for(auto i:bt)ans.pb(i);
			bt.clear();
			return true;
		}
		return false;
	}
	int le = st, ri;
	For(i,0,z.size()){
		ri = le;
		For(j,i,z.size()){
			ri+= abs(z[j].fi-z[j].se)+1;
			bt.pb({le, ri-1});
			rev(i,j);
			if(bf(turn-1)){
				return true;
			}
			rev(i,j);
			bt.pob();
		}
		le+= abs(z[i].fi-z[i].se)+1;
	}
	return false;
}

void solve(int le,int ri){
	int cnt = 0, ls, dir;
	hit = 0;
	z.clear();
	rep(i,le,ri){
		if(cnt){
			if(abs(ls-x[i])>1)upd(i-cnt,i-1,z), cnt = 0;
			else {
				if(cnt==1)dir = ls<x[i];
				else {
					if((ls<x[i])!=dir)z.pb({i-cnt,i-1}), cnt = 0;
				}
			}
		}
		++cnt, ls = x[i];
	}
	upd(ri-cnt+1,ri,z);
	
	if(hit==1){
		ans.pb({le,ri});
		return;
	}
	if(bf(2))return;
	bf(3);
}

int main(){
//	cout<<fixed<<setprecision(10);
//	freopen("input.txt", "r", stdin);
//	freopen("output.txt","w",stdout);
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	cin>>n;
	rep(i,1,n){
		cin>>x[i];
	}
	rep(i,1,n){
		mx = max(mx, x[i]);
		if(i==mx){
			if(st){
				solve(st,i);
				assert(ans.size()<=3);
			}
			st = 0;
		}
		else if(!st)st = i;
	}
	cout<<ans.size()<<endl;
	reverse(all(ans));
	for(auto i:ans)cout<<i.fi<<" "<<i.se<<endl;
	return 0;
}