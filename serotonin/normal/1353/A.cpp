#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int sz = 3e5+5;

int a[sz];

int main()
{
    int t;
    cin >> t;
    while(t--) {
        ll n, m;
        cin >> n >> m;
        if(n == 1) puts("0");
        else if(n == 2) printf("%lld\n", m);
        else printf("%lld\n", m << 1);
    }
}