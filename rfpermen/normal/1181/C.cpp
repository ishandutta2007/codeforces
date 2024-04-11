#include <bits/stdc++.h>
 
#pragma GCC optimize("O2")
#pragma GCC optimize("Ofast")
#pragma GCC optimize("unroll-loops")
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
 
ll n,m,ans,ls,cnt;
short int bt,z[26][MAX][MAX],x[MAX][MAX],col,a,b,c;
char C;
 
int main(){
//	cout<<fixed<<setprecision(15);
//    freopen("input.txt", "r", stdin);
//	freopen("output.txt","w",stdout);
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    cin>>n>>m;
    rep(i,1,n)rep(j,1,m){
    	cin>>C;
    	x[i][j] = C-'a';
		rep(k,0,25)z[k][i][j] = z[k][i-1][j];
		z[x[i][j]][i][j]++;
	}
    rep(sz,1,n){
    	rep(i,1,n){
    		if(i+sz*3-1>n)break;
    		a = b = c = 26;
    		rep(j,1,m){
    			col = 26;
    			
    			bt = i+sz-1;
    			col = x[bt][j];
    			if(a!=col){cnt = 0; a = col;}
    			if(z[col][bt][j]-z[col][i-1][j]!=sz){cnt = 0; continue;}
    			
    			bt+=sz;
    			if(col==x[bt][j]){cnt = 0; continue;}
    			col = x[bt][j];
    			if(b!=col){cnt = 0; b = col;}
    			if(z[col][bt][j]-z[col][i+sz-1][j]!=sz){cnt = 0; continue;}
    			
    			bt+=sz;
    			if(col==x[bt][j]){cnt = 0; continue;}
    			col = x[bt][j];
    			if(c!=col){cnt = 0; c = col;}
    			if(z[col][bt][j]-z[col][i+sz+sz-1][j]!=sz){cnt = 0; continue;}
    			
    			++cnt;
    			ans+=cnt;
			}
		}
	}
	cout<<ans<<endl;
	return 0;
}