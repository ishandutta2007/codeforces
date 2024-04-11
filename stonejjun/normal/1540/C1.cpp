#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;
typedef double dl;
typedef pair<dl,dl> pdi;
typedef pair<ll,ll> pii;
typedef pair<ll,pii> piii;

#define ff first
#define ss secondac
#define eb emplace_back
#define ep emplace
#define pb push_back
#define mp make_pair
#define all(x) (x).begin(), (x).end()
#define compress(v) sort(all(v)), v.erase(unique(all(v)), v.end())
#define IDX(v, x) lower_bound(all(v), x) - v.begin()
//cout<<fixed;
//cout.precision(12);

struct poi{
    ll val,xx,yy;
};

vector<ll> x;
ll n,m;
ll mod=1e9+7;
string s;
string t;
ll arr[1010101];
vector<ll> v[1010101];
ll dep[1010101];
ll vis[1010101];
ll par[1000][20];
ll revt;
ll revtm[1010];
ll rt;
ll brr[1010101];
ll crr[1010101];
ll pre[1010101];
ll cpre[1010101];
ll dp[101][10101];


int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    ll i,j,k;
    cin>>n;
    ll a,b,c,d;
    for(i=1;i<=n;i++){
        cin>>crr[i];
        cpre[i]=cpre[i-1]+crr[i];
    }
    for(i=1;i<n;i++)
        cin>>brr[i];
    
    cin>>m>>k;
    pre[1]=k;
    for(i=2;i<=n;i++)
        pre[i]=pre[i-1]+brr[i-1];

    for(i=1;i<=n;i++)
        pre[i]=pre[i-1]+pre[i];
   

    dp[0][0]=1;
    for(i=1;i<=n;i++){
        for(j=max(0LL,pre[i]);j<=cpre[i];j++){
            for(k=0;k<=crr[i];k++){
                if(j>=k)
                    dp[i][j]+=dp[i-1][j-k];
            }
            dp[i][j]=dp[i][j]%mod;
            //cout<<i<<' '<<j<<' '<<dp[i][j]<<'\n';
        }
    }
    ll ans=0;
    for(i=0;i<=10100;i++)
        ans=(ans+dp[n][i])%mod;

    cout<<ans;

    
}