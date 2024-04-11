#include <bits/stdc++.h>
 
#pragma GCC optimize("O3")
using namespace std;
#define ll long long
#define ull unsigned long long
#define rep(i,n,N) for(ll i=n;i<=N;++i)
#define rap(i,n,N) for(ll i=n;i>=N;--i)
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
#define plll pair<ll,pii>
#define piiii pair<pii,pii>
#define psi pair<string,int>
#define endl "\n"
const int MAX = 1e2+5;
const ll MAX2 = 11;
const ll MOD = 1000000007;
const ll INF = 1e18;
const int dr[]={1,0,-1,0,1,1,-1,-1,0};
const int dc[]={0,1,0,-1,1,-1,1,-1,0};
const double pi = acos(-1);
const double EPS = 1e-9;
const int block = 450;

int n,m,cnt,hit,nr,nc;
char x[MAX][MAX];
bool vis[MAX][MAX];

void dfs(int r,int c){
	vis[r][c] = 1;
	rep(k,0,3){
		nr = r+dr[k], nc = c+dc[k];
		if(x[nr][nc]!='#'||vis[nr][nc])continue;
		dfs(nr,nc);
	}
	return;
}

int main(){
//	cout<<fixed<<setprecision(15);
//    freopen("input.txt", "r", stdin);
//	freopen("output.txt","w",stdout);
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    cin>>n>>m;
    rep(i,1,n)rep(j,1,m)cin>>x[i][j];
    rep(i,1,n)rep(j,1,m){
    	if(x[i][j]=='.')continue;
    	x[i][j] = '.';
    	++hit;
    	memset(vis,0,sizeof vis);
    	cnt = 0;
    	rep(I,1,n)rep(J,1,m){
    		if(x[I][J]=='.'||vis[I][J])continue;
    		dfs(I,J);
    		++cnt;
		}
		if(cnt>=2)return cout<<"1\n",0;
    	x[i][j] = '#';
	}
	if(hit<3)cout<<"-1\n";
	else cout<<"2\n";
	return 0;
}