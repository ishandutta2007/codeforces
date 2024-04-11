#include <bits/stdc++.h>
 
#pragma GCC optimize("O2")
//#pragma GCC optimize("Ofast")
//#pragma GCC optimize("unroll-loops")
using namespace std;
#define ll long long
#define ull unsigned long long
#define rep(i,n,N) for(int i=n;i<=N;++i)
#define rap(i,n,N) for(int i=n;i>=N;--i)
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
#define db(x) cout << ">>>>>> " << #x << " -> " << x << endl;
#define all(x) x.begin(),x.end()
#define pii pair<int,int> 
#define pll pair<ll,ll>
#define piii pair<int,pii>
#define piiii pair<pii,pii>
#define psi pair<string,int>
#define endl "\n"
const int MAX = 1e3+5;
const ll MAX2 = 11;
const ll MOD = 1000000007;
const ll INF = 2e18;
const int dr[]={1,0,-1,0,1,1,-1,-1,0};
const int dc[]={0,1,0,-1,1,-1,1,-1,0};
const double pi = acos(-1);
const double EPS = 1e-9;
const int block = 450;

int n,m,vis[MAX][MAX],ans,nr,nc,z;
char x[MAX][MAX],hs[4];

inline bool inside(int r,int c){
	return r>0&&c>0&&r<=n&&c<=m;
}

int dfs(int r,int c,int cnt){
	if(cnt>z){cout<<"Poor Inna!\n"; exit(0);}
	if(vis[r][c])return vis[r][c];
	int ret = 0;
	rep(k,0,3){
		nr = r+dr[k], nc = c+dc[k];
		if(!inside(nr,nc))continue;
		if(x[nr][nc]!=hs[cnt%4])continue;
		ret = max(ret,dfs(nr,nc,cnt+1));
	}
	return vis[r][c] = ret+1;
}

int main(){
//	cout<<fixed<<setprecision(15);
//    freopen("input.txt", "r", stdin);
//	freopen("output.txt","w",stdout);
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    hs[0] = 'D', hs[1] = 'I', hs[2] = 'M', hs[3] = 'A';
    cin>>n>>m;
    z = n*m;
    rep(i,1,n)rep(j,1,m)cin>>x[i][j];
    rep(i,1,n)rep(j,1,m){
    	if(vis[i][j])continue;
    	if(x[i][j]=='D')ans = max(ans,dfs(i,j,1));
	}
	if(ans/4)cout<<ans/4<<endl;
	else cout<<"Poor Dima!\n";
	return 0;
}