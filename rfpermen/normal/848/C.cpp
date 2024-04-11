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
const int block = 850;
inline ll pw(ll x,ll y,ll md=MOD){ll ret=1;x%=md;while(y){if(y&1)ret=ret*x%md;x=x*x%md,y>>=1;}return ret;}
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

int n,q,x[MAX],y[MAX],cnt[MAX],id,ls[MAX],op,l,r,pos;
set<int> pd; //pending
set<int> ril[MAX];
vi ori[MAX];
vector<pii> ql[MAX], qr[MAX];
bool ad;

unsigned int bit[MAX], ans[MAX];

inline void upd(int i,int val){
	for(; i<=n; i+=i&-i)bit[i]+= val;
	return;
}

unsigned int ret;
inline unsigned int que(int i){
	ret = 0;
	for(; i>0; i^=i&-i)ret+= bit[i];
	return ret;
}

inline void relax(){
	if(ad){
		mems(bit, 0);
		mems(ls, 0);
		int ttl = 0;
		rep(i,1,n){ // solve untuk last occurence
			pos = x[i];
			if(cnt[pos]>1){
				if(ls[pos]){
					upd(ls[pos], -ls[pos]);
					ttl-= ls[pos];
				}
				ls[pos] = i;
				upd(i, i);
				ttl+= i;
			}
			for(auto &j:qr[i]){
				ans[j.se]+= ttl-que(j.fi-1);
			}
			qr[i].clear();
		}
		
		mems(bit, 0);
		mems(ls, 0);
		rap(i,n,1){ // solve untuk first occurence
			pos = x[i];
			if(cnt[pos]>1){
				if(ls[pos]){
					upd(ls[pos], -ls[pos]);
					ttl-= ls[pos];
				}
				ls[pos] = i;
				upd(i, i);
			}
			for(auto &j:ql[i]){
				ans[j.se]-= que(j.fi);
			}
			ql[i].clear();
		}
		ad = 0;
	}
	
	mems(cnt,0);
	rep(i,1,n){
		x[i] = y[i];
		++cnt[x[i]];
		ori[i].clear();
		ril[i].clear();
	}
	rep(i,1,n)ori[x[i]].pb(i), ril[x[i]].insert(i);
	pd.clear();
	return;
}

int main(){
//	cout<<fixed<<setprecision(6);
//	freopen("input.txt", "r", stdin);
//	freopen("output.txt","w",stdout);
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	cin>>n>>q;
	rep(i,1,n)cin>>x[i], ++cnt[x[i]], y[i] = x[i], ori[x[i]].pb(i), ril[x[i]].insert(i);
	auto it = pd.begin();
	auto it2 = ori[0].begin();
	while(q--){
		cin>>op>>l>>r;
		if(op==1){
			if(y[l]==r)continue;
			pd.insert(y[l]);
			pd.insert(r);
			ril[y[l]].erase(l);
			y[l] = r;
			ril[y[l]].insert(l);
			if(pd.size()>block)relax();
		}
		else {
			ad = 1;
			++id;
			ql[l].pb({r,id});
			qr[r].pb({l,id});
			for(auto i:pd){
				it2 = lower_bound(all(ori[i]), l);
				if(it2!=ori[i].end() && *it2<=r){
					ans[id]+= *it2;
					it2 = upper_bound(all(ori[i]), r);
					--it2;
					ans[id]-= *it2;
				}
				
				it = ril[i].lower_bound(l);
				if(it!=ril[i].end() && *it<=r){
					ans[id]-= *it;
					it = ril[i].upper_bound(r);
					--it;
					ans[id]+= *it;
				}
			}
		}
	}
	relax();
	rep(i,1,id)cout<<ans[i]<<endl;
	return 0;
}