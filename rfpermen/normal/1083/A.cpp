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
const int MAX = 3e5+5;
const ll MOD = 998244353;
const ll MOD2 = 2010405347;
const ll INF = 2e18;
const int dr[]={1,0,-1,0,1,1,-1,-1,0};
const int dc[]={0,1,0,-1,1,-1,1,-1,0};
const double pi = acos(-1);
const double EPS = 1e-9;
const int block = 100;
inline ll pw(ll x,ll y,ll md=MOD){ll ret=1;x%=md;while(y){if(y&1)ret=ret*x%md;x=x*x%md,y>>=1;}return ret;}
mt19937_64 rng(chrono::steady_clock::now().time_since_epoch().count());

ll n,a,b,c,x[MAX],dp[MAX],dp2[MAX],ans;
vector<pii> v[MAX];
vector<ll> z[MAX];

void dfs(int nw,int par){
	z[nw].pb(0);
	z[nw].pb(0);
	for(auto i:v[nw])if(i.fi!=par){
		dfs(i.fi, nw);
		z[nw].pb(dp[i.fi] - i.se);
	}
	sort(all(z[nw]));
	reverse(all(z[nw]));
	dp[nw] = z[nw][0] + x[nw];
	dp2[nw] = z[nw][1] + x[nw];
	return;
}

void f(int nw,int par){
	ans = max(ans, dp[nw]);
	ll a,b,val;
	for(auto i:v[nw])if(i.fi!=par){
		if(dp[i.fi] - i.se == dp[nw] - x[nw]){
			val = dp2[nw] - i.se + x[i.fi];
		}
		else {
			val = dp[nw] - i.se + x[i.fi];
		}
		a = dp[i.fi], b = dp2[i.fi];
		
		if(val >= dp[i.fi])dp2[i.fi] = dp[i.fi], dp[i.fi] = val;
		else dp2[i.fi] = max(dp2[i.fi], val);
		
		f(i.fi, nw);
		
		dp[i.fi] = a;
		dp2[i.fi] = b;
	}
	return;
}

int main(){
//	cout<<fixed<<setprecision(10);
//	freopen("input.txt", "r", stdin);
//	freopen("output.txt","w",stdout);
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	cin>>n;
	rep(i,1,n)cin>>x[i];
	rep(i,2,n){
		cin>>a>>b>>c;
		v[a].pb({b,c});
		v[b].pb({a,c});
	}
	dfs(1,0);
	f(1,0);
	cout<<ans<<endl;
	return 0;
}