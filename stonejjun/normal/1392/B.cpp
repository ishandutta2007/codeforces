#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;
typedef pair<ll,ll> pii;

#define ff first
#define ss second
#define ep emplace_back
#define eb emplace
#define pb push_back



int main(){
    ll t;
    scanf("%lld",&t);
    while(t--){
        ll arr[201010]={0,};
        ll i,j,k,l,m,n,mx=-1e18,mn=1e18;
        scanf("%lld %lld",&n,&m);
        for(i=1;i<=n;i++){
            scanf("%lld",&arr[i]);
            mx=max(mx,arr[i]);
            mn=min(mn,arr[i]);
        }
        if(m%2){
            for(i=1;i<=n;i++){
                arr[i]=mx-arr[i];
                printf("%lld ",arr[i]);
            }
            printf("\n");
        }
        else{
            for(i=1;i<=n;i++){
                arr[i]=(mx-mn)-(mx-arr[i]);
                printf("%lld ",arr[i]);
            }
            printf("\n");
        }

    }
}