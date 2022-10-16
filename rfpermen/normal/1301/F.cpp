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
const int block = 200;
inline ll pw(ll x,ll y,ll md=MOD){ll ret=1;x%=md;while(y){if(y&1)ret=ret*x%md;x=x*x%md,y>>=1;}return ret;}
inline void add(int &a,int b,int md=MOD){a=a+b>=md?a+b-md:a+b;}

int n,m,k,tc,v[42][42],x[MAX][MAX],vis[42][MAX][MAX],r,c,nr,nc,a,b,d,ans,tmp;
queue<pii> q;

int main(){
//	cout<<fixed<<setprecision(10);
//	freopen("input.txt", "r", stdin);
//	freopen("output.txt","w",stdout);
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	cin>>n>>m>>k;
	rep(i,1,n)rep(j,1,m)cin>>x[i][j];
	
	rep(i,1,k)rep(j,1,k){
		if(i!=j)v[i][j] = MOD;
//		else v[i][j] = 1;
	}
	mems(vis,-1);
	rep(o,1,k){
		rep(i,1,n)rep(j,1,m)if(x[i][j]==o){
			vis[o][i][j] = 0;
			q.push({i,j});
		}
		while(!q.empty()){
			r = q.front().fi, c = q.front().se; q.pop();
			rep(l,0,3){
				nr = r+dr[l], nc = c+dc[l];
				if(nr && nc && nr<=n && nc<=m && vis[o][nr][nc]==-1){
//					ou3(o,nr,nc);
					vis[o][nr][nc] = vis[o][r][c]+1;
					q.push({nr,nc});
				}
			}
		}
		rep(i,1,n)rep(j,1,m)if(x[i][j]!=o)v[x[i][j]][o] = min(v[x[i][j]][o],vis[o][i][j]);
	}
	rep(o,1,k)rep(i,1,k)rep(j,1,k)v[i][j] = min(v[i][j],v[i][o]+v[o][j]+1);
	
	cin>>tc;
	rep(ntc,1,tc){
		cin>>a>>b>>c>>d;
		ans = abs(a-c) + abs(b-d);
		if(x[a][b]==x[c][d])ans = min(ans,1);
		
		nr = x[a][b], nc = x[c][d];
		ans = min(ans,v[nr][nc]+2);
//		db(ans);
		
		rep(o,1,k)rep(l,1,k){
			if(ans<=2)break;
			//jl jl
			if(o==l){
				ans = min(ans,vis[o][a][b] + vis[o][c][d] + 1);
			}
			else {
				ans = min(ans,vis[o][a][b] + vis[l][c][d] + 2 + v[o][l]);
			}
			
			//tl jl
			if(o==l){
				ans = min(ans,v[o][nr] + vis[o][c][d] + 1 + (o!=nr));
			}
			else {
				ans = min(ans,v[o][nr] + vis[l][c][d] + 2 + v[o][l] + (o!=nr));
			}
			
			swap(a,c), swap(b,d), swap(nr,nc);
			//jl tl
			if(o==l){
				ans = min(ans,v[o][nr] + vis[o][c][d] + 1 + (o!=nr));
			}
			else {
				ans = min(ans,v[o][nr] + vis[l][c][d] + 2 + v[o][l] + (o!=nr));
			}
			swap(a,c), swap(b,d), swap(nr,nc);
		}
		cout<<ans<<endl;
	}
	return 0;
}