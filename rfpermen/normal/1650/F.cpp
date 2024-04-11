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
const int MAX = 5e5+5;
const ll MOD = 1000000007;
const ll MOD2 = 2010405347;
const ll INF = 2e18;
const int dr[]={1,0,-1,0,1,1,-1,-1,0};
const int dc[]={0,1,0,-1,1,-1,1,-1,0};
const double pi = acos(-1);
const double EPS = 1e-9;
inline ll pw(ll x,ll y,ll md=MOD){ll ret=1;x%=md;while(y){if(y&1)ret=ret*x%md;x=x*x%md,y>>=1;}return ret;}
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

int tc,n,k,dp[MAX][105],a,b,c,res,z[MAX];
pii x[MAX];
vector<ari(3)> y[MAX];
vi ans[MAX],jaw;
bool st;

int f(int nw,int rem){
	if(rem<=0)return 0;
	if(nw==y[a].size())return MOD;
	int &ret = dp[nw][rem];
	if(ret!=-1)return ret;
	return ret = min(f(nw+1,rem), f(nw+1,rem-y[a][nw][1]) + y[a][nw][0]);
}

void bt(int nw,int rem){
	if(rem<=0)return;
	if(dp[nw][rem]==f(nw+1,rem-y[a][nw][1]) + y[a][nw][0]){
		ans[a].pb(y[a][nw][2]);
		bt(nw+1,rem-y[a][nw][1]);
	}
	else {
		bt(nw+1,rem);
	}
}

int main(){
//	cout<<fixed<<setprecision(2);
//	freopen("input.txt", "r", stdin);
//	freopen("output.txt","w",stdout);
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	cin>>tc;
	rep(ntc,1,tc){
		cin>>k>>n;
		rep(i,1,k)cin>>x[i].fi, x[i].se = i, y[i].clear(), ans[i].clear();
		rep(i,1,n){
			cin>>a>>b>>c;
			y[a].pb({b,c,i});
		}
		st = 1;
		rep(i,1,k){
			For(j,0,y[i].size())mems(dp[j],-1);
			a = i;
			res = f(0,100);
			st&= res<=x[i].fi;
			if(!st)break;
//			out(res,x[i].fi);
			z[i] = res;
			bt(0,100);
		}
		if(!st){
			cout<<"-1\n";
			continue;
		}
		int wk = 0;
		jaw.clear();
		sort(x+1,x+1+k);
		rep(i,1,k){
			a = x[i].se;
			wk+= z[a];
			if(wk>x[i].fi)st = 0;
			if(!st)break;
			for(int j:ans[a])jaw.pb(j);
		}
		if(!st)cout<<"-1\n";
		else {
			cout<<jaw.size()<<endl;
			for(int i:jaw)cout<<i<<" "; cout<<endl;
		}
	}
	return 0;
}