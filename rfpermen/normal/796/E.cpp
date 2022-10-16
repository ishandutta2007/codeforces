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
const int MAX = 1e3+5;
const ll MOD = 1000000007;
const ll MOD2 = 2010405347;
const ll INF = 2e18;
const int dr[]={1,0,-1,0,1,1,-1,-1,0};
const int dc[]={0,1,0,-1,1,-1,1,-1,0};
const double pi = acos(-1);
const double EPS = 1e-9;
const int block = 400;
inline ll pw(ll x,ll y,ll md=MOD){ll ret=1;x%=md;while(y){if(y&1)ret=ret*x%md;x=x*x%md,y>>=1;}return ret;}
inline void add(int &a,int b,int md=MOD){a=a+b>=md?a+b-md:a+b;}

int n,p,k,o,z,ans;
ll x[2][MAX];
bool a[2][MAX];
vector<int> dp[MAX][52][2];

int f(int nw,int rem,bool mv,int ls){
	if(nw>n)return 0;
	if(ls==k)ls = mv = 0;
	int &ret = dp[nw][ls][mv][rem];
	if(ret!=-1)return ret;
	if(!rem){
		if(ls)return ret = popcount(x[mv][nw-ls]>>ls);
		return ret = 0;
	}
	ret = ls ? f(nw+1,rem,mv,ls+1) : f(nw+1,rem,mv,ls);
	if(!ls){
		if(a[0][nw])ret = max(ret,f(nw+1,rem-1,0,1)+1);
		if(a[1][nw])ret = max(ret,f(nw+1,rem-1,1,1)+1);
	}
	else {
		if(a[mv][nw])++ret;
		else if(a[mv^1][nw]){
			ret = max(ret,f(nw+(k-ls),rem-1,mv^1,k-ls) + 
						popcount((x[mv][nw-ls]>>ls) | (x[mv^1][nw]&((1ll<<(k-ls))-1))));
		}
	}
	return ret;
}

int main(){
//	cout<<fixed<<setprecision(10);
//	freopen("input.txt", "r", stdin);
//	freopen("output.txt","w",stdout);
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	cin>>n>>p>>k;
	cin>>o;
	rep(i,1,o){
		cin>>z;
		a[0][z] = 1;
	}
	cin>>o;
	rep(i,1,o){
		cin>>z;
		a[1][z] = 1;
	}
	if((n+k-1)/k*2<=p){
		rep(i,1,n)if(a[0][i] || a[1][i])++ans;
		cout<<ans<<endl;
		return 0;
	}
	rep(i,1,n)rep(j,0,k){
		dp[i][j][0].resize(p+1,-1);
		dp[i][j][1].resize(p+1,-1);
	}
	rep(i,1,n)For(j,0,k){
		if(i+j>n)break;
		if(a[0][i+j])x[0][i]|= 1ll<<j;
		if(a[1][i+j])x[1][i]|= 1ll<<j;
	}
	cout<<f(1,p,0,0)<<endl;
	return 0;
}