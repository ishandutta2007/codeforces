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
const int MAX = 1e4+5;
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

int n,m,k,a[MAX],b[MAX],nw,x,y,nx,ny,o,vis[MAX];
vi r[MAX],c[MAX];
map<pii,int> pos;
deque<int> dq;
bool vr[MAX],vc[MAX],vis2[MAX];


int main(){
//	cout<<fixed<<setprecision(10);
//	freopen("input.txt", "r", stdin);
//	freopen("output.txt","w",stdout);
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	cin>>n>>m>>k;
	rep(i,1,k){
		cin>>a[i]>>b[i];
		pos[{a[i],b[i]}] = i;
		r[a[i]].pb(b[i]);
		c[b[i]].pb(a[i]);
	}
	mems(vis,-1);
	vis[pos[{1,1}]] = 0;
	dq.pb(pos[{1,1}]);
	while(!dq.empty()){
		nw = dq.back(); dq.pob();
		if(vis2[nw])continue;
		vis2[nw] = 1;
		x = a[nw], y = b[nw];
		rep(i,0,3){
			nx = x+dr[i], ny = y+dc[i];
			if(pos.count({nx,ny})){
				o = pos[{nx,ny}];
				if(vis[o]==-1 || vis[o]>vis[nw]){
					vis[o] = vis[nw];
					dq.pb(o);
				}
			}
		}
		rep(nx,x-2,x+2){
			if(nx<0)continue;
			if(!vr[nx]){
				vr[nx] = 1;
				for(int i:r[nx]){
					o = pos[{nx,i}];
					if(vis[o]==-1){
						vis[o] = vis[nw]+1;
						dq.pf(o);
					}
				}
			}
		}
		rep(ny,y-2,y+2){
			if(ny<0)continue;
			if(!vc[ny]){
				vc[ny] = 1;
				for(int i:c[ny]){
					o = pos[{i,ny}];
					if(vis[o]==-1){
						vis[o] = vis[nw]+1;
						dq.pf(o);
					}
				}
			}
		}
	}
	if(pos.count({n,m}))cout<<vis[pos[{n,m}]]<<endl;
	else {
		int ans = MOD;
		x = n, y = m;
		rep(nx,x-1,x+1){
			for(int i:r[nx]){
				o = pos[{nx,i}];
				if(vis[o]!=-1)ans = min(ans,vis[o]+1);
			}
		}
		rep(ny,y-1,y+1){
			for(int i:c[ny]){
				o = pos[{i,ny}];
				if(vis[o]!=-1)ans = min(ans,vis[o]+1);
			}
		}
		
		if(ans==MOD)ans = -1;
		cout<<ans<<endl;
	}
	return 0;
}