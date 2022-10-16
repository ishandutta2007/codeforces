#include<bits/stdc++.h>
 
#pragma GCC optimize("O3")
#pragma GCC target("tune=native")
#pragma GCC optimize("unroll-loops")
 
using namespace std;
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
#define revsort(a,b) sort(a,b), reverse(a,b)
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
const int MAX = 200+5;
const ll MOD = 998244353;
const ll MOD2 = 2010405347;
const ll INF = 2e18;
const int dr[]={1,0,-1,0,1,1,-1,-1,0};
const int dc[]={0,1,0,-1,1,-1,1,-1,0};
const double pi = acos(-1);
const double EPS = 1e-9;
inline ll pw(ll x,ll y,ll md=MOD){ll ret=1;x%=md;while(y){if(y&1)ret=ret*x%md;x=x*x%md,y>>=1;}return ret;}
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

ll n,x[MAX][MAX],dp[MAX][MAX],ans[MAX];

ll f(int le,int ri){
	if(le>ri)return 0;
	if(le==ri)return x[n][le]-x[n][le-1];
	ll &ret = dp[le][ri];
	if(ret!=-1)return ret;
	ret = INF;
	rep(i,le,ri)ret = min(ret, f(le,i-1) + f(i+1,ri));
	ret+= x[n][ri]-x[n][le-1] - (x[ri][ri]-x[ri][le-1]-x[le-1][ri]+x[le-1][le-1]);
	return ret;
}

void bt(int le,int ri,int par){
	if(le>ri)return;
	if(le==ri){
		ans[le] = par;
		return;
	}
	ll ret = dp[le][ri] - (x[n][ri]-x[n][le-1] - (x[ri][ri]-x[ri][le-1]-x[le-1][ri]+x[le-1][le-1]));
	rep(i,le,ri)if(ret == f(le,i-1) + f(i+1,ri)){
		ans[i] = par;
		bt(le,i-1,i);
		bt(i+1,ri,i);
		break;
	}
	return;
}

int main(){
//	cout<<fixed<<setprecision(2);
//	freopen("input.txt", "r", stdin);
//	freopen("output.txt","w",stdout);
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	cin>>n;
	rep(i,1,n)rep(j,1,n){
		cin>>x[i][j];
		x[i][j]+= x[i-1][j]+x[i][j-1]-x[i-1][j-1];
	}
//	rep(i,1,n){
//		rep(j,1,n)cout<<x[i][j]<<" "; cout<<endl;
//	}
	mems(dp,-1);
	f(1,n);
	bt(1,n,0);
	rep(i,1,n)cout<<ans[i]<<" "; cout<<endl;
	return 0;
}