#include <bits/stdc++.h>
 
#pragma GCC optimize("O3")
//#pragma GCC optimize("unroll-loops")
 
using namespace std;
#define ll long long
#define ull unsigned long long
#define rep(i,n,N) for(int i=n;i<=N;++i)
#define asd(i,n,N) for(int i=n;i< N;++i)
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
#define db(x) cout << ">>>> " << #x << " -> " << x << endl
#define out(x,y) cout << ">> " << x << " " << y << endl
#define mems(x,y) memset(x,y,sizeof x)
#define all(x) x.begin(),x.end()
#define rng() ((rand()<<16)|rand())
#define pii pair<int,int> 
#define pll pair<ll,ll>
#define plll pair<ll,pll>
#define piii pair<int,pii>
#define piiii pair<pii,pii>
#define psi pair<string,int>
#define endl '\n'
const int MAX = 1e5+5;
const ll MOD = 1000000007;
const ll MOD2 = 2010405347;
const ll INF = 2e18;
const int dr[]={1,0,-1,0,1,1,-1,-1,0};
const int dc[]={0,1,0,-1,1,-1,1,-1,0};
const double pi = acos(-1);
const double EPS = 1e-9;
const int block = 555;

int n,nr,nc;
bool vis[10][10][50];
char x[10][10];

inline bool cek(int r,int c){
	if(r<1)return 1;
	return x[r][c]!='S';
}

void dfs(int r,int c,int t){
	if(r==1 && c==8){
		cout<<"WIN\n";
		exit(0);
	}
	if(t>45)return;
	vis[r][c][t] = 1;
	int nr,nc;
	rep(i,0,8){
		nr = r+dr[i], nc = c+dc[i];
		if(nr>0&&nc>0&&nr<9&&nc<9 && !vis[nr][nc][t+1] && cek(nr-t,nc) && cek(nr-t-1,nc)){
			dfs(nr,nc,t+1);
		}
	}
	return;
}

int main(){
// cout<<fixed<<setprecision(10);
// freopen("trip.in", "r", stdin);
// freopen("output.txt","w",stdout);
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    rep(i,1,8)rep(j,1,8)cin>>x[i][j];
    dfs(8,1,0);
    cout<<"LOSE\n";
    return 0;
}