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

ll tc,n,m,a,b,s,t,ans,vis[MAX],vis2[MAX],dp[MAX],dp2[MAX];
vi v[MAX];
vii e;
queue<int> q;

void bfs(ll *vis, int sta){
	rep(i,1,n)vis[i] = -1;
	vis[sta] = 0;
	q.push(sta);
	int nw;
	while(!q.empty()){
		nw = q.front(); q.pop();
		for(int i:v[nw]){
			if(vis[i]==-1){
				vis[i] = vis[nw]+1;
				q.push(i);
			}
		}
	}
	return;
}

ll f(int nw,ll *dp,ll *vis){
	if(!vis[nw])return 1;
	ll &ret = dp[nw];
	if(ret!=-1)return ret;
	ret = 0;
	for(int i:v[nw]){
		if(vis[i]+1==vis[nw]){
			ret+= f(i,dp,vis);
		}
	}
	ret%= MOD;
	return ret;
}

int main(){
//	cout<<fixed<<setprecision(2);
//	freopen("input.txt", "r", stdin);
//	freopen("output.txt","w",stdout);
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	cin>>tc;
	rep(ntc,1,tc){
		cin>>n>>m>>s>>t;
		rep(i,1,n)v[i].clear();
		e.clear();
		rep(i,1,m){
			cin>>a>>b;
			e.pb({a,b});
			v[a].pb(b);
			v[b].pb(a);
		}
		bfs(vis,s);
		bfs(vis2,t);
		int dis = vis[t], mn;
		rep(i,1,n)dp[i] = dp2[i] = -1;
		ans = f(t,dp,vis);
		rep(i,1,n){
			if(vis[i]+vis2[i]==dis+1){
				a = b = 0;
				for(int j:v[i]){
					if(vis[j]==vis[i]-1)a+= f(j, dp, vis);
					if(vis2[j]==vis2[i]-1 && vis[j]+vis2[j]!=dis+1)b+= f(j, dp2, vis2);
				}
				a%= MOD;
				b%= MOD;
//				ou3(i,a,b);
				ans+= a*b%MOD;
			}
			else if(vis[i]+vis2[i]==dis){
				b = 0;
				for(int j:v[i]){
					if(vis2[j]==vis2[i] && vis[j]+vis2[j]!=dis+1)b+= f(j, dp2, vis2);
				}
				b%= MOD;
//				if(b)out(i,b);
				ans+= f(i,dp,vis)*b%MOD;
			}
		}
		cout<<ans%MOD<<endl;
	}
	return 0;
}