#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll sz=2e5+5,p=998244353;

ll two[sz];
char a[sz],b[sz];

int main()
{
    ll i,j,k;
    two[0]=1;
    for(i=1;i<sz;i++) two[i]=(two[i-1]*2)%p;
    ll n,m;
    scanf("%I64d %I64d %s %s", &n, &m, a, b);
    ll x=0;
    for(i=0;i<m-n;i++) {
        if(b[i]=='1') x++;
    }
    j=m-n; ///b
    if(j<0) j=0;
    k=n-m; ///a
    if(k<0) k=0;

    ll ans=0;

    for(i=0;i+j<m;i++) {
        if(b[i+j]=='1') x++;
        if(a[i+k]=='1') {
            ans+=(x*two[n-1-i-k])%p;
            ans=ans%p;
        }
    }

    if(ans<0) ans+=p;
    printf("%I64d\n", ans);
}