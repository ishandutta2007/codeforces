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
ll brr[1010101];

ll cnt[1010101];

int main(){
    ll i,j,k,l,m,n;
    scanf("%lld",&n);
    for(i=1;i<=n;i++){
        scanf("%lld",&k);
        arr[k]=i;
    }
    for(i=1;i<=n;i++){
        scanf("%lld",&k);
        brr[k]=i;
    }
    for(i=1;i<=n;i++){
        cnt[(n+arr[i]-brr[i])%n]++;
    }
    ll ans=0;
    for(i=0;i<=n;i++)
        ans=max(ans,cnt[i]);
    printf("%lld",ans);

}