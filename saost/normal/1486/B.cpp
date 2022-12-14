#include <iostream>
#include <algorithm>
using namespace std;
long long t, n, a[10005], b[10005];

int main()
{
    scanf("%lld", &t);
    while (t--) {
        scanf("%lld", &n);
        for(int i=0; i<n; i++) scanf("%lld%lld", &a[i], &b[i]);
        sort(a, a+n);
        sort(b, b+n);
        if (n&1) cout << "1\n";
        else cout << (a[n/2] - a[n/2-1] + 1) * (b[n/2] - b[n/2-1] + 1) << '\n';
    }
}