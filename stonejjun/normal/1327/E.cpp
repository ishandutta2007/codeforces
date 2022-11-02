#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;
typedef pair<ll,ll> pii;
#define ff first
#define ss second
#define eb emplace_back
#define pb push_back

ll arr[1010101];
ll mod=998244353;

ll ch[1010101];

ll lsp(ll a,ll b){
    ll ret=1;
    while(b){
        if(b%2) ret=(ret*a)%mod;
        a=(a*a)%mod;
        b/=2;
    }
    return ret;
}

int main(){
	ll i,j,k,l,m,a,b,c,d,n;
	ll ans=6;
	scanf("%lld",&n);
    ll now2=0;
    ll now3=0;
    ll now1;
	for(i=1;i<=n;i++){
        now1=lsp(10,i);
        now1=(now1*i)%mod;
        now2+=now3;
        now2=(now2+mod)%mod;
        arr[i]=(now1-now2+mod)%mod;
        now2+=arr[i];
        now3+=arr[i];
    }
    for(i=n;i>=1;i--)
        printf("%lld ",arr[i]);


}