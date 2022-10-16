#include <bits/stdc++.h>
 
#pragma GCC optimize("O2")
//#pragma GCC optimize("unroll-loops")
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
#define piiii pair<pii,pii>
#define psi pair<string,int>
#define endl '\n'
const int MAX = 1e2+5;
const ll MAX2 = 11;
const ll MOD = 1000000007;
const ll MOD2 = 1000005329;
const ll INF = 2e18;
const int dr[]={1,0,-1,0,1,1,-1,-1,0};
const int dc[]={0,1,0,-1,1,-1,1,-1,0};
const double pi = acos(-1);
const double EPS = 1e-9;
const int block = 2000;

ll tc,n,m,x[MAX][MAX],y[MAX][MAX],ans;

int main(){
//	cout<<fixed<<setprecision(4);
//    freopen("input.txt", "r", stdin);
//	freopen("input.txt","w",stdout);
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    cin>>tc;
    rep(ntc,1,tc){
    	cin>>n>>m;
    	rep(i,1,n)rep(j,1,m)cin>>x[i][j], x[i][j]-= i+j;
    	ans = INF;
    	rep(i,1,n)rep(j,1,m){
    		if(x[1][1]>=x[i][j])y[1][1] = x[1][1]-x[i][j];
    		else y[1][1] = INF;
    		rep(a,2,n){
    			if(x[a][1]>=x[i][j])y[a][1] = y[a-1][1] + x[a][1]-x[i][j];
    			else y[a][1] = INF;
			}
    		rep(a,2,m){
    			if(x[1][a]>=x[i][j])y[1][a] = y[1][a-1] + x[1][a]-x[i][j];
    			else y[1][a] = INF;
			}
    		rep(a,2,n)rep(b,2,m){
    			if(x[a][b]>=x[i][j])y[a][b] = min(y[a-1][b],y[a][b-1]) + x[a][b]-x[i][j];
    			else y[a][b] = INF;
			}
    		ans = min(ans, y[n][m]);
		}
		cout<<ans<<endl;
	}
    return 0;
}