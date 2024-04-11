#include <bits/stdc++.h>

#pragma GCC optimize("O2")
using namespace std;
#define ll long long
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
#define pii pair<short int,short int> 
#define pll pair<ll,ll>
#define piii pair<int,pii>
#define endl "\n"
const int MAX = 1e3+5;
const int MOD=1000000000 + 7;
const ll INF=1e18;
const int nr[]={0,1,0,-1,1,1,-1,-1,  2,2,-2,-2,1,1,-1,-1};
const int nc[]={1,0,-1,0,1,-1,1,-1,  1,-1,1,-1,2,-2,2,-2};

ll x;
pii y[205];
short int n,k,dp[201][5010],mx;

int main(){
//    cout<<fixed<<setprecision(9);
//    freopen("input.txt", "r", stdin);
//	freopen("output.txt","w",stdout);
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    cin>>n>>k;
    rep(i,1,n){
    	cin>>x;
    	while(x%2==0)y[i].fi++, x/=2;
    	while(x%5==0)y[i].se++, x/=5;
	}
	memset(dp,-1,sizeof dp);
	dp[0][0] = 0;
	rep(i,1,n){
		rap(j,i-1,0){
			rep(o,0,5000){
				if(dp[j][o]==-1)continue;
				dp[j+1][o+y[i].se] = max((int)dp[j+1][o+y[i].se],dp[j][o]+y[i].fi);
			}
		}
	}
	rep(i,1,5000)mx = max((int)mx,min(i,(int)dp[k][i]));
	cout<<mx<<endl;
    return 0;
}