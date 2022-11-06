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
        int n;
        scanf("%d", &n);
        for(int i=0; i<n; i++) scanf("%d", &a[i]);
        sort(a,a+n);
        int ans = sz;
        for(int i=1; i<n; i++) ans = min(ans, a[i]-a[i-1]);
        printf("%d\n", ans);
    }
}