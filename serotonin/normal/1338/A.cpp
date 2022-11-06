#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int sz = 1e5+5;

int main()
{
    int t;
    cin >> t;
    while(t--) {
        int n, mn = INT_MIN, x, ans = 0;
        scanf("%d", &n);
        for(int i=0; i<n; i++) {
            scanf("%d", &x);
            if(i) ans = max(ans, mn - x);
            mn = max(mn, x);
        }

        int k = 0;
        while(ans) ans >>= 1, k++;

        printf("%d\n", k);
    }
}