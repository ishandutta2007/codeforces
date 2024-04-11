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
//#define ff fi.fi
//#define fs fi.se
//#define sf se.fi
//#define ss se.se
#define lc (id<<1)
#define rc ((id<<1)|1)
#define db(x) cerr << ">>>>>> " << #x << " -> " << x << endl
#define nani(x) cerr <<  "Line " << __LINE__ << ": " << #x << " is " << x << endl
#define all(x) x.begin(),x.end()
#define pii pair<int,int> 
#define pll pair<ll,ll>
#define plll pair<ll,pll>
#define piii pair<int,pii>
#define piiii pair<pii,pii>
#define psi pair<string,int>
#define endl '\n'
const int MAX = 15e2+5;
const ll MAX2 = 11;
const ll MOD = 1000000007;
const ll MOD2 = 1000005329;
const ll INF = 2e18;
const int dr[]={1,0,-1,0,1,1,-1,-1,0};
const int dc[]={0,1,0,-1,1,-1,1,-1,0};
const double pi = acos(-1);
const double EPS = 1e-9;
const int block = 2000;
 
int n,m,sx,sy;
pii vir[MAX][MAX];
char x[MAX][MAX];
 
void dfs(int r,int c,int vr,int vc){
	vir[r][c] = {vr,vc};
	int nr,nc,nvr,nvc;
	rep(k,0,3){
		nr = r+dr[k], nc = c+dc[k];
		if(nr>n)nr = 1;
		else if(nr<1)nr = n;
		if(nc>m)nc = 1;
		else if(nc<1)nc = m;
		if(x[nr][nc]=='#')continue;
		nvr = vr+dr[k], nvc = vc+dc[k];
		if(vir[nr][nc]==make_pair(nvr,nvc))continue;
		if(vir[nr][nc].fi!=-1){
			cout<<"Yes\n";
			exit(0);
		}
		dfs(nr,nc,nvr,nvc);
	}
	return;
}
 
int main(){
//	cout<<fixed<<setprecision(10);
//    freopen("input.txt", "r", stdin);
//	freopen("output.txt","w",stdout);
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    cin>>n>>m;
    rep(i,1,n)rep(j,1,m){
    	cin>>x[i][j];
    	if(x[i][j]=='S')sx = i, sy = j;
	}
	memset(vir,-1,sizeof vir);
	dfs(sx,sy,sx,sy);
	cout<<"No\n";
    return 0;
}