#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int sz=3e5+5, inf=2e9+5;

char s[sz];

int main()
{
    int t;
    cin >> t;
    while(t--) {
        ll k,x;
        scanf("%lld %lld", &k, &x);
        printf("%lld\n", (k-1)*9+x);
    }
}