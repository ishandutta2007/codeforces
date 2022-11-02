#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;
typedef pair<ll,ll> pii;
#define ff first
#define ss second
 
string s;

ll dp[30][30];
ll cnt[30];

int main(){
    ll i,j,k,l,m,n,u,v,c;
    cin>>s;
    n=s.size();
    for(i=0;i<n;i++){
        k=s[i]-'a';
        for(j=0;j<26;j++){
                dp[k][j]+=cnt[j];
        }
        
        cnt[k]++;
    }

    ll ans=0;
    for(i=0;i<26;i++)
        for(j=0;j<26;j++){
            ans=max(ans,dp[i][j]);
            ans=max(ans,cnt[i]);
        }
    printf("%lld",ans);
}