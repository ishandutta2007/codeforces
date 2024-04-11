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
ll arr[1010101];
ll brr[1010101];
ll lcnt[1010101];
ll ans=0;
ll n,m;
ll tree[1010101];
ll fac[1010101];
ll mod=998244353;
ll cnt[2010101];
ll pre[2010101];
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    ll t,T;
    cin>>t;
    while(t--){

        ll i,j,k,l;
        ll a,b,c;
        cin>>n>>m;

        for(i=1;i<=n;i++){
            cin>>arr[i];
            cnt[arr[i]]++;
        }
        
        for(i=1;i<=m;i++){
            pre[i]=pre[i-1]+cnt[i];
          //  cout<<i<<' '<<pre[i]<<'\n';
        }
        ll chk=1;

        for(i=2;i<=m;i++){
            ll x=i;
            if(cnt[x]==0) continue;
            //cout<<i<<' '<<x<<'\n';
            for(j=1;j<=m/x;j++){
               // cout<<i<<' '<<x<<' '<<j<<'\n';
                //cout<<pre[x*(j+1)-1]<<pre[x*j-1]<<'\n';
                if(cnt[j]==0&&pre[min(m,x*(j+1)-1)]-pre[x*j-1]) chk=0;
            }
        }

        if(chk==0) cout<<"No"<<'\n';
        else cout<<"Yes"<<'\n';


        for(i=0;i<=m;i++){
            pre[i]=cnt[i]=0;
        }
    }



    
    
}