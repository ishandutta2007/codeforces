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
const int MAX = 2e5+5;
const ll MOD = 998244353;
const ll MOD2 = 2010405347;
const ll INF = 2e18;
const int dr[]={1,0,-1,0,1,1,-1,-1,0};
const int dc[]={0,1,0,-1,1,-1,1,-1,0};
const double pi = acos(-1);
const double EPS = 1e-9;
const int block = 1000;
inline ll pw(ll x,ll y,ll md=MOD){ll ret=1;x%=md;while(y){if(y&1)ret=ret*x%md;x=x*x%md,y>>=1;}return ret;}
mt19937_64 rng(chrono::steady_clock::now().time_since_epoch().count());

int n,x[MAX],a,b,ans[MAX],bit[MAX],id;
map<int,int> hs;
vector<pii> qu[MAX];

inline void upd(int i){
	for(; i<=id; i+=i&-i)++bit[i];
	return;
}
int ret;
inline int que(int i){
	ret = 0;
	for(; i; i^=i&-i)ret+= bit[i];
	return ret;
}

int main(){
//	cout<<fixed<<setprecision(10);
//	freopen("input.txt", "r", stdin);
//	freopen("output.txt","w",stdout);
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	cin>>n;
	rep(i,1,n)cin>>x[i], hs[x[i]];
	for(auto i:hs)hs[i.fi] = ++id;
	rep(i,1,n)x[i] = hs[x[i]];
	
	rep(k,1,block){
		rep(i,1,n){
			a = k*(i-1) + 2, b = min(n, k*i + 1);
			rep(j,a,b)ans[k]+= x[j]<x[i];
			if(b==n)break;
		}
	}
	
	For(k,block+1,n){
		rep(i,1,n){
			a = k*(i-1) + 2, b = min(n, k*i + 1);
			qu[b].pb({x[i],k});
			qu[a-1].pb({x[i],-k});
			if(b==n)break;
		}
	}
	rep(i,1,n){
		upd(x[i]);
		for(auto j:qu[i]){
			if(j.se<0){
				j.se*= -1;
				ans[j.se]-= que(j.fi-1);
			}
			else {
				ans[j.se]+= que(j.fi-1);
			}
		}
	}
	
	For(i,1,n)cout<<ans[i]<<" "; cout<<endl;
	return 0;
}