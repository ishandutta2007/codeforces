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
ll mod=998244353;
ll arr[1010101];
ll lst[1010101];
ll chk[1010101];
ll dp[3030][3030];
ll lf[101010];

ll n,m;
ll inf=1e18;
ll mval;

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    ll t,T;

    ll i,j,k,l;
//    ll chk=0,cnt=0,val;
    ll a=0,b=0,c=0,d=0,x=0;
    ll e,f,g,h;
    ll cnta=0,cntb=0;
    ll lawin=0;
    //ll ans=1;

    cin>>t;
    while(t--){
        cin>>n;
        for(i=1;i<=n;i++)
            cin>>arr[i];
        for(i=1;i<=n;i++){
            lst[i]=0;
            for(j=1;j<=n;j++)
                dp[i][j]=0;
        }

        for(j=1;j<=n;j++){
            vector<ll> v;
            for(i=j-1;i>=1;i--){
                if(arr[i]==arr[j]){
                    v.pb(i);
                }
                dp[i][j]=dp[i][j-1];
                
                for(auto k:v){
                    dp[i][j]=max(dp[i][j],1+dp[i][k]+dp[k+1][j]);
                }
                
                //cout<<i<<' '<<j<<' '<<' '<<dp[i][j]<<'\n';
            }
        }
        cout<<n-1-dp[1][n]<<'\n';
    }
    

    
}