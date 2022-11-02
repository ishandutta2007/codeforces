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
string s;

int main(){
    ll t;
    scanf("%lld",&t);
    while(t--){
        ll i,j,k,l,m,n;
        string s;
        cin>>s;
        n=s.size();
        ll zf[1010]={0,};
        ll zb[1010]={0,};
        ll of[1010]={0,};
        ll ob[1010]={0,};
        for(i=1;i<=n;i++){
            zf[i]=zf[i-1];
            of[i]=of[i-1];
            if(s[i-1]=='0') zf[i]++;
            else of[i]++;
        }
        for(i=n;i>=1;i--){
            zb[i]=zb[i+1];
            ob[i]=ob[i+1];
            if(s[i-1]=='0') zb[i]++;
            else ob[i]++;
        }
        ll ans=1e18;
        for(i=1;i<n;i++){
            ans=min(ans,zf[i]+min(zb[i+1],ob[i+1]));
            ans=min(ans,of[i]+min(zb[i+1],ob[i+1]));
        }
        if(n==1) ans=0;
        printf("%lld\n",ans);
    }
}