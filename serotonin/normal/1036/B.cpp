#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
main()
{
    ll q,n,m,t,k,ans;
    scanf("%I64d", &q);
    while(q--) {
        scanf("%I64d %I64d %I64d", &n, &m, &k);
        ll s=min(n,m)+abs(n-m);
        if(k<s) {
            puts("-1");
            continue;
        }
        else {
            t=abs(n-m);
            k-=min(n,m);
            ans=min(n,m);
            if(t%2) k--;
            else if(k%2) k-=2;
        }
        ans+=k;
        printf("%I64d\n", ans);
    }
}