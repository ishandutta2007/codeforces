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
const int MAX = 1e3+10;
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

int bruh[] = {1, 3+(3<<4), 7+(7<<4)+(7<<8), (1<<16)-1};
int n,x[8],dp[2][1<<16],z[MAX],gd,id,lp,tf[4][4],res,ans;
bool nw,ft;
char c;
vi now,nx;

int main(){
//	cout<<fixed<<setprecision(10);
//	freopen("input.txt", "r", stdin);
//	freopen("output.txt","w",stdout);
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	cin>>n;
	rep(i,0,3){
		cin>>x[i];
		rep(j,0,3){
			tf[i][j] = (bruh[j]<<i)^((1<<16)-1);
		}
	}
	rep(i,0,3)rep(j,1,n){
		cin>>c;
		z[j]|= (c=='*')<<i;
	}
	gd = (((((z[4]<<4)|z[3])<<4)|z[2])<<4)|z[1];
	nw = 0, ft = 1;
	mems(dp[nw],-1);
	dp[nw][gd] = 0;
	now.pb(gd);
	rep(j,1,n){
		rep(i,0,3){
			nx.clear();
			for(int mask:now){
				if(!(mask&(1<<i)))nx.pb(mask);
				lp = 3-i;
				rep(k,0,lp){
					res = mask&tf[i][k];
					if(dp[nw][res]==-1){
						dp[nw][res] = dp[nw][mask] + x[k];
						nx.pb(res);
					}
					else dp[nw][res] = min(dp[nw][res], dp[nw][mask] + x[k]);
				}
			}
			now = nx;
		}
		mems(dp[ft],-1);
		for(int &mask:now){
			res = (mask>>4) | (z[j+4]<<12);
			dp[ft][res] = dp[nw][mask];
			mask = res;
		}
		nw^= 1, ft^= 1;
	}
	cout<<dp[nw][0]<<endl;
	return 0;
}