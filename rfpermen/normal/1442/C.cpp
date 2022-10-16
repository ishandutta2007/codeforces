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
const int MAX = 3e5+5;
const ll MOD = 998244353;
const ll MOD2 = 2010405347;
const ll INF = 2e18;
const int dr[]={1,0,-1,0,1,1,-1,-1,0};
const int dc[]={0,1,0,-1,1,-1,1,-1,0};
const double pi = acos(-1);
const double EPS = 1e-9;
const int block = 315;
inline ll pw(ll x,ll y,ll md=MOD){ll ret=1;x%=md;while(y){if(y&1)ret=ret*x%md;x=x*x%md,y>>=1;}return ret;}
inline void add(int &a,int b,int md=MOD){a=a+b>=md?a+b-md:a+b;}

int n,m,a,b,vis[21][MAX],nw,k,cs,nx,o,ans;
pii vis2[2][MAX];
vector<int> v[MAX],u[MAX];

PQr(ari(3)) pq;

int main(){
//	cout<<fixed<<setprecision(10);
//	freopen("input.txt", "r", stdin);
//	freopen("output.txt","w",stdout);
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    cin>>n>>m;
    while(m--){
    	cin>>a>>b;
    	v[a].pb(b);
    	u[b].pb(a);
	}
	rep(i,0,19)rep(j,1,n)vis[i][j] = MOD;
	rep(i,0,1)rep(j,1,n)vis2[i][j] = {MOD,MOD};
	vis[0][1] = 0;
	pq.push({0,0,1});
	while(!pq.empty()){
		nw = pq.top()[2], cs = pq.top()[1], k = pq.top()[0];
		pq.pop();
		if(k>19){
			o = k&1;
			if(vis2[o][nw]!=mp(k,cs))continue;
			if(vis2[o^1][nw]>mp(k+1,cs)){
				vis2[o^1][nw] = {k+1,cs};
				pq.push({k+1,cs,nw});
			}
			if(k&1){
				for(int i:u[nw])if(vis2[o][i]>mp(k,cs+1)){
					vis2[o][i] = mp(k,cs+1);
					pq.push({k,cs+1,i});
				}
			}
			else {
				for(int i:v[nw])if(vis2[o][i]>mp(k,cs+1)){
					vis2[o][i] = mp(k,cs+1);
					pq.push({k,cs+1,i});
				}
			}
		}
		else {
			if(vis[k][nw]!=cs)continue;
			if(k==19){
				if(vis2[0][nw]>mp(k+1,cs)){
					vis2[0][nw] = {k+1,cs};
					pq.push({k+1,cs,nw});
				}
			}
			else {
				if(vis[k+1][nw]>cs){
					vis[k+1][nw] = cs;
					pq.push({k+1,cs,nw});
				}
			}
			if(k&1){
				for(int i:u[nw])if(vis[k][i]>cs+1){
					vis[k][i] = cs+1;
					pq.push({k,cs+1,i});
				}
			}
			else {
				for(int i:v[nw])if(vis[k][i]>cs+1){
					vis[k][i] = cs+1;
					pq.push({k,cs+1,i});
				}
			}
		}
	}
	ans = MOD;
	rep(i,0,19)if(vis[i][n]!=MOD)ans = min(ans,vis[i][n]+(1<<i)-1);
	if(ans==MOD){
		if(vis2[0][n]<vis2[1][n])ans = (pw(2,vis2[0][n].fi)-1+vis2[0][n].se)%MOD;
		else ans = (pw(2,vis2[1][n].fi)-1+vis2[1][n].se)%MOD;
	}
	cout<<ans<<endl;
	return 0;
}