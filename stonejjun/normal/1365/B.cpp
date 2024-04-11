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

int main(){
    ll t;
    scanf("%lld",&t);
    while(t--){
        ll i,j,k,l,m,n;
        scanf("%lld",&n);
        ll arr[1000]={0,};
        ll cnt1=0;
        ll cnt2=0;
        ll chk=1;
        for(i=1;i<=n;i++){
            scanf("%lld",&arr[i]);
        }
        for(i=1;i<=n;i++){
        	scanf("%lld",&k);
        	if(k==0) cnt1++;
        	else cnt2++;
        }
        for(i=1;i<n;i++){
        	if(arr[i]>arr[i+1]) chk=0;
        }

        if(cnt1*cnt2||chk) printf("Yes\n");
        else printf("No\n");
    }
}