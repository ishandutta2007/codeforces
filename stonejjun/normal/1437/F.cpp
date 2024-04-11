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
//ll arr[1010101];

ll n,m;
string s;
vector<pii> ans;
vector<ll> v[202020];
vector<ll> rev[202020];
ll dis[20][202020];
pii dis2[202020];
ll inf=1e18;
ll day;
ll dp[5050][5050];
ll pdp[5050][5050];
ll hap[5050];
ll arr[5050];

ll fl(ll x){
    return max(0LL,x);
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    ll t,T;

    ll i,j,k,l;
    ll chk=0,cnt=0,val;
    ll a=0,b=0,c=0,d=0,x=0;
    ll e,f,g,h;
    ll cnta=0,cntb=0;
    ll lawin=0;
    //ll ans=1;

    cin>>n;
    for(i=1;i<=n;i++)
        cin>>arr[i];

    sort(arr+1,arr+1+n);

    for(i=1;i<=n;i++){
        for(j=1;j<i;j++){
            if(arr[j]*2<=arr[i])
                hap[i]=j;
        }
       // cout<<i<<' '<<hap[i]<<'\n';
        dp[i][1]=1;
        pdp[i][1]=i;
    }

    for(i=2;i<=n;i++)
        for(j=2;j<=i;j++){
            dp[i][j]+=dp[i][j-1]*fl(hap[i]-j+2);
            dp[i][j]%=mod;

            dp[i][j]+=pdp[hap[i]][j-1];
            dp[i][j]%=mod;

            pdp[i][j]=(pdp[i-1][j]+dp[i][j])%mod;
           // cout<<i<<' '<<j<<' '<<dp[i][j]<<'\n';
        }

    cout<<dp[n][n];

    
}