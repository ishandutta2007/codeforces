#include <bits/stdc++.h>

#pragma GCC optimize("O2")
using namespace std;
#define ll long long
#define ull unsigned long long
#define rep(i,n,N) for(int i=n;i<=N;i++)
#define rap(i,n,N) for(int i=(int)n;i>=(int)N;i--)
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
const int MAX = 1e5+5;
const ll MAX2 = 11;
const int MOD = 998244353;
const ll INF = 2e18;
const int dr[]={1,0,-1,0,1,1,-1,-1,0};
const int dc[]={0,1,0,-1,1,-1,1,-1,0};
const double pi = acos(-1);
const double EPS = 1e-9;

ll n,x[MAX],dp[MAX][201][2],y[201],z[201];

int main(){
	cout<<fixed<<setprecision(10);
//    freopen("input.txt", "r", stdin);
//	freopen("output.txt","w",stdout);
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    cin>>n;
    rep(i,1,n)cin>>x[i];
    dp[0][1][1] = 1;
    rep(i,1,n){
    	rep(j,1,200)y[j] = (y[j-1]+dp[i-1][j][1])%MOD, z[j] = (z[j-1]+dp[i-1][j][0])%MOD;
    	if(x[i]==-1){
    		rep(j,1,200){
    			x[i] = j;
    			dp[i][x[i]][0] = (z[x[i]-1]+y[x[i]-1]+MOD)%MOD;
				dp[i][x[i]][1] = (z[x[i]]-z[x[i]-1]+y[200]-y[x[i]-1]+2*MOD)%MOD;
			}
		}
		else {
			dp[i][x[i]][0] = (z[x[i]-1]+y[x[i]-1]+MOD)%MOD;
			dp[i][x[i]][1] = (z[x[i]]-z[x[i]-1]+y[200]-y[x[i]-1]+2*MOD)%MOD;
		}
	}
	rep(j,1,200)y[j] = (y[j-1]+dp[n][j][1])%MOD;
    cout<<y[200]<<endl;
	return 0;
}