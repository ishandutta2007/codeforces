#include <bits/stdc++.h>
 
#pragma GCC optimize("O2")
//#pragma GCC optimize("unroll-loops")
using namespace std;
#define ll long long
#define ull unsigned long long
#define rep(i,n,N) for(int i=n;i<=N;++i)
#define rap(i,n,N) for(ll i=n;i>=N;--i)
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
#define db(x) cout << ">>>>>> " << #x << " -> " << x << endl
#define all(x) x.begin(),x.end()
#define pii pair<int,int> 
#define pll pair<ll,ll>
#define plll pair<ll,pll>
#define piii pair<int,pii>
#define piiii pair<pii,pll>
#define psi pair<string,int>
#define endl '\n'
const int MAX = 50+5;
const ll MAX2 = 11;
const ll MOD = 1000000007;
const ll MOD2 = 1000005329;
const ll INF = 2e18;
const int dr[]={1,0,-1,0,1,1,-1,-1,0};
const int dc[]={0,1,0,-1,1,-1,1,-1,0};
const double pi = acos(-1);
const double EPS = 1e-9;
const int block = 2000;

int tc,n,m;
bool vis[MAX][MAX];
char x[MAX][MAX];
bool st;

void f(int r,int c){
	if(vis[r][c])return;
	vis[r][c] = true;
	int nr,nc;
	rep(k,0,3){
		nr = r+dr[k], nc = c+dc[k];
		if(x[nr][nc]!='#')f(nr,nc);
	}
	return;
}

int main(){
//	cout<<fixed<<setprecision(10);
//    freopen("input.txt", "r", stdin);
//	freopen("output.txt","w",stdout);
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    cin>>tc;
    rep(ntc,1,tc){
    	cin>>n>>m;
    	memset(x,'#',sizeof x);
    	rep(i,1,n)rep(j,1,m)cin>>x[i][j];
		st = 1;
		rep(i,1,n)rep(j,1,m)if(x[i][j]=='B'){
			rep(k,0,3)if(x[i+dr[k]][j+dc[k]]=='.')x[i+dr[k]][j+dc[k]] = '#';
		}
		memset(vis,0,sizeof vis);
		if(x[n][m]!='#')f(n,m);
		rep(i,1,n)rep(j,1,m)if(x[i][j]=='G')st&= vis[i][j];
		rep(i,1,n)rep(j,1,m)if(x[i][j]=='B')st&=!vis[i][j];
		cout<<(st ? "Yes" : "No")<<endl;
	}
	return 0;
}