#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;
typedef double dl;
typedef pair<dl,dl> pdi;
typedef pair<ll,ll> pii;
 
#define ff first
#define ss second
#define ep emplace_back
#define eb emplace
#define pb push_back
#define mp make_pair
#define all(x) (x).begin(), (x).end()
//cout<<fixed;
//cout.precision(12);

ll arr[5050];
ll typ[5050];
ll val[5050];
ll dp[5050];
ll pdp[2][5050];
ll prel[5050];
ll prer[5050];

ll n,m;

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    ll t,T;
    cin>>t;
    while(t--){
        ll i,j,k,l;
        cin>>n;
        for(i=1;i<=n;i++)
            cin>>typ[i];
        for(i=1;i<=n;i++)
            cin>>arr[i];

            for(j=0;j<=n;j++){
                dp[j]=0;
            }

        ll ans=0;

        for(j=2;j<=n;j++){
            for(i=j-1;i;i--){
                if(typ[i]==typ[j]) continue;
                ll x=dp[i];
                ll y=dp[j];
                ll val=abs(arr[i]-arr[j]);
                dp[i]=max(dp[i],y+val);
                dp[j]=max(dp[j],x+val);
                ans=max({ans,dp[i],dp[j]});
            }
        }
        cout<<ans<<'\n';


    }

}