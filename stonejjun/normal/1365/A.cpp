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
        scanf("%lld %lld",&n,&m);
        ll arr[100]={0,};
        ll brr[100]={0,};
        ll cnt1=n;
        ll cnt2=m;
        for(i=1;i<=n;i++){
            for(j=1;j<=m;j++){
                scanf("%lld",&k);
                if(k==1){
                    if(arr[i]==0){
                        arr[i]=1;
                        cnt1--;
                    }
                    if(brr[j]==0){
                        brr[j]=1;
                        cnt2--;
                    }
                }
            }
        }

        if(min(cnt1,cnt2)%2==0) printf("Vivek\n");
        else printf("Ashish\n");
    }
}