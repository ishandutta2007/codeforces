#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int sz=3e5+5, inf=2e9+5;

char s[sz];
ll a[sz];

int main()
{
    ll n,k,i,j;
    cin >> n >> k;
    for(i=0; i<n; i++) scanf("%lld", &a[i]);
    scanf("%s", s);
    ll ans=0,p=0;
    char c=s[0];
    for(i=0; i<=n; i++) {
        if(s[i]!=c) {
            sort(a+p, a+i);
            j=0;
            for(int q=i-1; q>=p; q--) {
                j++;
                ans+=a[q];
                //printf("%lld\n", a[q]);
                //printf("%lld\n", *it);
                if(j==k) break;
            }
            p=i;
        }
        c=s[i];
    }
    printf("%lld\n", ans);
}