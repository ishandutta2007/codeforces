#include <bits/stdc++.h>
 
#pragma GCC optimize("O3")
#pragma GCC target("tune=native")
//#pragma GCC optimize("unroll-loops")
 
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
#define mems(x,y) memset(x,y,sizeof x)
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
#define endl '\n'
const int MAX = 2e5+5;
const ll MOD = 1000000007;
const ll MOD2 = 2010405347;
const ll INF = 2e18;
const int dr[]={1,0,-1,0,1,1,-1,-1,0};
const int dc[]={0,1,0,-1,1,-1,1,-1,0};
const double pi = acos(-1);
const double EPS = 1e-9;
const int block = 315;
inline ll pw(ll x,ll y,ll md=MOD){ll ret=1;while(y){if(y&1)ret=ret*x%md;x=x*x%md,y>>=1;}return ret;}
inline void add(int &a,int b,int md=MOD){a=a+b>=md?a+b-md:a+b;}

int n,k,hit,a,b;
ll x[MAX],sm,pf[MAX];
double dv[MAX],dp[51][MAX],y[MAX];

void f(int rem,int l,int r,int optl,int optr){
	if(l>r)return;
	int mid = l+r>>1;
	int optid = mid;
	double opt = INF;
	a = optl, b = mid;
	double c = y[optl] - y[mid+1] - (dv[n] - dv[mid])*(pf[mid] - pf[optl-1]);
	
	for(int i = optl; i<=mid && i<=optr; ++i){
		if(dp[rem-1][i-1] + c < opt){
			opt = dp[rem-1][i-1] + c;
			optid = i;
		}
		c-= (dv[mid]-dv[i-1])*x[i];
	}
	
	dp[rem][mid] = opt;
	f(rem, l, mid-1, optl, optid);
	f(rem, mid+1, r, optid, optr);
	return;
}

int main(){
	cout<<fixed<<setprecision(10);
// freopen("input.txt", "r", stdin);
// freopen("output.txt","w",stdout);
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	cin>>n>>k;
	rep(i,1,n){
		cin>>x[i];
		dv[i] = dv[i-1] + 1.0/x[i];
		pf[i] = pf[i-1] + x[i];
	}
	rap(i,n,1)y[i] = y[i+1] + (dv[n]-dv[i-1])*x[i];
	rep(i,1,n){
		sm+= x[i];
		dp[1][i] = dp[1][i-1] + (double)sm/x[i];
	}
	
	rep(i,2,k)f(i,i,n,i,n);
	cout<<dp[k][n]<<endl;
	return 0;
}