#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int sz = 3e5+5;

int a[sz], b[sz];

int main()
{
    int t;
    cin >> t;
    while(t--) {
        int n, k;
        scanf("%d %d", &n, &k);
        for(int i=0; i<n; i++) scanf("%d", &a[i]);
        for(int i=0; i<n; i++) scanf("%d", &b[i]);

        sort(a, a+n);
        for(int i=0; i<k; i++) b[n+i] = a[i];
        sort(b, b+n+k, greater<int>());

        for(int i=0; i<k; i++) a[i] = b[i];

        int ans = 0;
        for(int i=0; i<n; i++) ans += a[i];

        printf("%d\n", ans);
    }
}