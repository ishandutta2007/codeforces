#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int sz=3e5+5;

ll a[sz];

int main()
{
    int t;
    cin >> t;
    while(t--) {
        int n;
        scanf("%d", &n);
        for(int i=0; i<n; i++) scanf("%lld", &a[i]);

        bool yes=0;
        for(ll i=0, j=0; i<n-1; i++) {
            j+=a[i];
            if(j<=0) yes=1;
        }
        for(ll i=n-1, j=0; i; i--) {
            j+=a[i];
            if(j<=0) yes=1;
        }

        if(yes) puts("NO");
        else puts("YES");
    }
}