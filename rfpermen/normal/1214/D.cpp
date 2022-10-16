#include <bits/stdc++.h>
 
#pragma GCC optimize("O3")
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
#define db(x) cerr << ">>>>>> " << #x << " -> " << x << endl
#define nani(x) cerr <<  "Line " << __LINE__ << ": " << #x << " is " << x << endl
#define all(x) x.begin(),x.end()
#define pii pair<int,int> 
#define pll pair<ll,ll>
#define plll pair<ll,pll>
#define pllll pair<pll,pll>
#define piii pair<int,pii>
#define piiii pair<pii,pii>
#define psi pair<string,int>
#define endl '\n'
const int MAX = 1e6+5;
const ll MAX2 = 11;
const ll MOD = 1000000007;
const ll MOD2 = 1000000006;
const ll INF = 2e18;
const int dr[]={1,0,-1,0,1,1,-1,-1,0};
const int dc[]={0,1,0,-1,1,-1,1,-1,0};
const double pi = acos(-1);
const double EPS = 1e-9;
const int block = 2000;
 
int n,m,a,b,nr,nc,cnt[MAX];
char c;
bool st;
vector<bool> x[MAX],vis[MAX],dp[MAX];

bool f(int r,int c){
	if(r>n||c>m||x[r][c])return 0;
	if(r==n && c==m)return dp[r][c] = 1;
	if(vis[r][c])return dp[r][c];
	vis[r][c] = 1;
	rep(i,0,1)dp[r][c] = dp[r][c]|f(r+dr[i],c+dc[i]);
	return dp[r][c];
}
 
int main(){
//	cout<<fixed<<setprecision(10);
//    freopen("input.txt", "r", stdin);
//	freopen("output.txt","w",stdout);
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    cin>>n>>m;
    rep(i,1,n){
    	x[i].pb(0);
    	rep(j,1,m)cin>>c, x[i].pb(c=='#'), st|=(c=='#');
    	rep(j,0,m)vis[i].pb(0), dp[i].pb(0);
	}
	if(n==1||m==1)return cout<<1-st<<endl,0;
	if(!f(1,1))return cout<<"0\n",0;
	rep(i,1,n)rep(j,1,m)cnt[i+j]+= dp[i][j];
	n+=m-1;
	rep(i,3,n)if(cnt[i]<2)return cout<<"1\n",0;
	cout<<"2\n";
    return 0;
}