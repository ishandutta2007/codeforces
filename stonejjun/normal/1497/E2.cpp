#include<bits/stdc++.h>
using namespace std;
typedef int ll;
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
ll mod=1000000007;
ll arr[1010101];
ll lchk[310101];
ll vis[10101010];
ll pre[303030][23];
ll dp[303030][23];

ll n,m;
string s;
vector<pii> ans;
vector<ll> v;
bool sf(ll a,ll b){
    if(arr[a]%2&&arr[b]%2==0) return 0;
    if(arr[a]%2==0&&arr[b]%2) return 1;
    return a<b;
}

vector <ll> p;
ll com[1010100];

void sieve (ll n) {
    for (ll i = 2; i < n; ++i) {
        if (com[i]==0) p.pb(i);
        for(auto k:p){
            if(i*k>=n) break;
            com[i*k]=1;
            if(i%k==0) break;

        }
    }
}

ll sol(ll x,ll y){ //  ,  
    if(x>n||y>m) return 1e9;
    if(dp[x][y]!=-1) return dp[x][y];
    dp[x][y]=1e9;
    ll fl=y; // 
    for(ll i=x+1;i<=n;i++){
        if(lchk[i]<x) continue;
        //cout<<x<<' '<<y<<' '<<i<<'\n';
        dp[x][y]=min(dp[x][y],1+sol(i,fl));
        fl++;
        if(fl>m) break;
    }
    if(fl<=m){
       //cout<<x<<' '<<y<<'\n';
        dp[x][y]=1;
    }
    //cout<<x<<' '<<y<<' '<<dp[x][y]<<'\n';
    return dp[x][y];
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    ll t,T;
    ll i,j,k,l;
    ll chk=0,cnt=0,val;
    ll a=0,b=0,c=0,d=0;
    ll e,f,g,h;
    ll cnta=0,cntb=0;
    ll lawin=0;
    //ll ans=0;

    sieve(10000);

    cin>>t;
    while(t--){
        cin>>n>>m;
        //ll ans=1;
        for(i=1;i<=n;i++){
            cin>>arr[i];
            for(auto k:p){
                while(arr[i]%(k*k)==0){
                    arr[i]/=k;
                    arr[i]/=k;
                }
            }
        }
        for(i=1;i<=n;i++){
            lchk[i]=vis[arr[i]];
            vis[arr[i]]=i;
            //cout<<i<<' '<<lchk[i]<<'\n';
        }

        for(i=0;i<=n;i++){
            for(j=0;j<=m;j++)
                dp[i][j]=-1;
        }

        sol(1,0);
        cout<<dp[1][0]<<'\n';


        for(i=1;i<=n;i++){
            vis[arr[i]]=0;
            lchk[i]=0;
        }

    }
    
}