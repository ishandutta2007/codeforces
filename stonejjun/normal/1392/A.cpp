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
        scanf("%lld",&n);
        for(i=1;i<=n;i++){
            scanf("%lld",&arr[i]);
        }
        sort(arr+1,arr+1+n);
        if(arr[1]!=arr[n]) printf("1\n");
        else printf("%lld\n",n);

    }
}