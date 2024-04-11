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


vector<ll> v[101010];
vector<ll> x;
ll cnt[1010101];
ll arr[1010101];
ll lcnt[1010101];
ll ans=0;
ll n,m;

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    ll t,T;
    ll i,j,k,l;
    ll a,b,c;

    for(i=1;i<=100000;i++)
        v[i].pb(0);

    cin>>n>>m;
    for(i=1;i<=n;i++)
        for(j=1;j<=m;j++){
            cin>>a;
            v[i].pb(a);
            x.pb(a);
        }

    x.pb(0);
    sort(x.begin(), x.end());
    x.erase(unique(x.begin(), x.end()),x.end());

    for(i=1;i<=n;i++)
        for(j=1;j<=m;j++){
            v[i][j]=lower_bound(x.begin(), x.end(),v[i][j])-x.begin();
            lcnt[v[i][j]]++;
        }

    for(i=1;i<=n;i++)
        for(j=1;j<=m;j++){
            ll x=v[i][j];
            //cout<<i<<' '<<j<<' '<<x<<'\n';
            ans+=cnt[x]*i;
            cnt[x]++;
            ans-=(lcnt[x]-cnt[x])*i;
        }

    for(i=0;i<=300000;i++)
        cnt[i]=0;


    for(j=1;j<=m;j++)
        for(i=1;i<=n;i++){
            ll x=v[i][j];
            ans+=cnt[x]*j;
            cnt[x]++;
            ans-=(lcnt[x]-cnt[x])*j;
        }
    cout<<ans;
}