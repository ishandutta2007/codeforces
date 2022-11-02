#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;
typedef pair<ll,ll> pii;
 
#define ff first
#define ss second
#define ep emplace_back
#define eb emplace
#define pb push_back
 
ll arr[1010101];
ll ans[1010101];
 
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    ll n;
    cin>>n;
    ll i,j,k,l,m,t;
    ll sum=0,sum2=0;
    for(i=1;i<=n;i++){
        cin>>arr[i];
        sum+=arr[i];
    }
    ll val=sum/n;
    ll fix=n/2+1;
    for(i=1;i<=n;i++){
        ans[i]=val+i-fix;
        sum2+=ans[i];
    }
    //printf("%lld %lld\n",sum,sum2);
    for(i=1;i<=n;i++){
        if(sum2<sum){
            ans[i]++;
            sum2++;
        }
    }
    for(i=1;i<=n;i++){
        if(sum2<sum){
            ans[i]++;
            sum2++;
        }
    }
    for(i=1;i<=n;i++){
        if(sum2<sum){
            ans[i]++;
            sum2++;
        }
    }
    for(i=1;i<=n;i++)
        cout<<ans[i]<<' ';
 
 
}