#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll sz=3e5+5;

int main()
{
    int t;
    cin >> t;
    while(t--) {
        int n;
        cin >> n;
        ll s=0, x=0;
        for(int i=0; i<n; i++) {
            ll k;
            scanf("%lld", &k);
            s+=k;
            x^=k;
        }

        ll a=x^(1LL<<56);
        s+=a;

        s=(1LL<<57)-s;
        ll b=0,c=0;
        for(ll i=1; i<=s; i<<=1) {
            if(s&i) {
                b|=(i>>1);
                c|=(i>>1);
            }
        }

        printf("3\n");
        printf("%lld %lld %lld\n", a, b, c);
    }
}