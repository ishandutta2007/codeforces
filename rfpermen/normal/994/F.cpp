#include <bits/stdc++.h>
 
#pragma GCC optimize("O3")
#pragma GCC target("tune=native")
#pragma GCC optimize("unroll-loops")
 
using namespace std;
#define ll long long
#define ull unsigned long long
#define rep(i,n,N) for(int i=(n);i<=(N);++i)
#define For(i,n,N) for(int i=(n);i< (N);++i)
#define rap(i,n,N) for(int i=(n);i>=(N);--i)
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
#define all(x) x.begin(),x.end()
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
//#define endl '\n'
const int MAX = 20+5;
const ll MOD = 1000000007;
const ll MOD2 = 2010405347;
const ll INF = 2e18;
const int dr[]={0,0,-1,1,1,1,-1,-1};
const int dc[]={1,-1,0,0,1,-1,-1,1};
const double pi = acos(-1);
const double EPS = 1e-9;
const int block = 315;
inline ll pw(ll x,ll y,ll md=MOD){ll ret=1;while(y){if(y&1)ret=ret*x%md;x=x*x%md,y>>=1;}return ret;}
inline void add(int &a,int b,int md=MOD){a=a+b>=md?a+b-md:a+b;}

int n,id;
ll le,ri,mid,ans,dp[55][55],ls;
pll x[55];
vector<pll> v[55];
bool vis[55][55];

ll f(int nw,int rem){
	if(nw>n)return 0;
	if(vis[nw][rem])return dp[nw][rem];
	vis[nw][rem] = 1;
	ll ret = INF, tmp = 0;
	if(rem>=v[nw].size())ret = f(nw+1,rem-v[nw].size());
	rep(i,1,v[nw].size()){
		tmp+= v[nw][i-1].fi - v[nw][i-1].se*mid;
		if(rem>=v[nw].size()-i)ret = min(ret,f(nw+1,rem+2*i-v[nw].size()) + tmp);
	}
	return dp[nw][rem] = ret;
}

int main(){
//	cout<<fixed<<setprecision(10);
// freopen("asd.csv", "r", stdin);
// freopen("output.txt","w",stdout);
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	cin>>n;
	rep(i,1,n)cin>>x[i].fi, x[i].fi*= 1000;
	rep(i,1,n)cin>>x[i].se;
	sort(x+1,x+1+n);
	reverse(x+1,x+1+n);
	rep(i,1,n){
		if(x[i].fi!=ls)ls = x[i].fi, ++id;
		v[id].pb(x[i]);
	}
	n = id;
	le = 1, ri = 2e11;
	while(le<=ri){
		mid = le+ri>>1;
		mems(vis,0);
		if(f(1,0)<=0)ans = mid, ri = mid-1;
		else le = mid+1;
	}
	cout<<ans<<endl;
	return 0;
}