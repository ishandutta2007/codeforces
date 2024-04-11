#include <bits/stdc++.h>
 
#pragma GCC optimize("O3")
//#pragma GCC target("tune=native")
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
const int MAX = 1e3+5;
const ll MOD = 998244353;
const ll MOD2 = 2010405347;
const ll INF = 6e13;
const int dr[]={1,0,-1,0,1,1,-1,-1,0};
const int dc[]={0,1,0,-1,1,-1,1,-1,0};
const double pi = acos(-1);
const double EPS = 1e-9;
const int block = 315;
inline ll pw(ll x,ll y,ll md=MOD){ll ret=1;while(y){if(y&1)ret=ret*x%md;x=x*x%md,y>>=1;}return ret;}
inline void add(int &a,int b,int md=MOD){a=a+b>=md?a+b-md:a+b;}

int n,m,x,y,a,b,vis[2][MAX],nw,ans;
bool v[MAX][MAX];
queue<int> q;

void bfs(bool id,int st){
	mems(vis[id],-1);
	vis[id][st] = 0;
	q.push(st);
	while(!q.empty()){
		nw = q.front(); q.pop();
		rep(i,1,n)if(v[nw][i] && vis[id][i]==-1){
			vis[id][i] = vis[id][nw]+1;
			q.push(i);
		}
	}
	return;
}

int main(){
//	cout<<fixed<<setprecision(10);
// freopen("input.txt", "r", stdin);
// freopen("output.txt","w",stdout);
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	cin>>n>>m>>x>>y;
	while(m--){
		cin>>a>>b;
		v[a][b] = 1;
		v[b][a] = 1;
	}
	bfs(0,x);
	bfs(1,y);
	nw = vis[0][y];
	
	rep(i,1,n)rep(j,i+1,n)if(!v[i][j]){
		if(min(vis[0][i]+vis[1][j],vis[0][j]+vis[1][i])+1>=nw)++ans;
	}
	cout<<ans<<endl;
	return 0;
}