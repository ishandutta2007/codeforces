#include <bits/stdc++.h>

#pragma GCC optimize("O3")
using namespace std;
#define ll long long
#define ull unsigned long long
#define rep(i,n,N) for(ll i=n;i<=N;++i)
#define rap(i,n,N) for(ll i=n;i>=N;--i)
#define mp make_pair
#define pb push_back
#define pob pop_back
#define pf push_front
#define pof pop_front
#define fi first
#define se second
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
const int MOD = 998244353;
const ll INF = 2e18;
const int dr[]={0,1,0,-1,0,1,1,-1,-1, 2,2,-2,-2,1,1,-1,-1};
const int dc[]={0,0,1,0,-1,1,-1,1,-1, 1,-1,1,-1,2,-2,2,-2};
const double pi = acos(-1);
const double EPS = 1e-9;

int n,m,q,cnt,vis[MAX][MAX],a,b,nr,nc;
char x[MAX][MAX];

void dfs(int r,int c){
	vis[r][c] = -1;
	rep(k,1,4){
		nr = r+dr[k], nc = c+dc[k];
		if(vis[nr][nc]==-1)continue;
		if(x[nr][nc]=='*')++cnt;
		else dfs(nr,nc);
	}
}
void dfs2(int r,int c){
	vis[r][c] = cnt;
	rep(k,1,4){
		nr = r+dr[k], nc = c+dc[k];
		if(vis[nr][nc]==-1)dfs2(nr,nc);
	}
}

int main(){
//	cout<<fixed<<setprecision(10);
//    freopen("input.txt", "r", stdin);
//	freopen("output.txt","w",stdout);
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    cin>>n>>m>>q;
    rep(i,1,n)rep(j,1,m)cin>>x[i][j];
    while(q--){
    	cin>>a>>b;
    	if(vis[a][b])cout<<vis[a][b]<<endl;
    	else {
    		cnt = 0;
    		dfs(a,b);
    		dfs2(a,b);
    		cout<<vis[a][b]<<endl;
		}
	}
	return 0;
}