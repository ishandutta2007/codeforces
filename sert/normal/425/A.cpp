#include <cstdio>
#include <iostream>
#include <algorithm>
#include <ctime>
#include <map>
#include <string>
using namespace std;
const int N = 2001;
int n, t, ans = -1e9, cur, len, lc, lb;
int a[N], b[N], c[N];
int main() {
    // freopen("a.in", "r", stdin);
    // freopen("a.out", "w", stdout);
    cin >> n >> t;
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    for (int i = 0; i < n; i++)
        for (int j = i + 1; j <= n; j++) {
            lc = lb = 0;
            for (int k = 0; k < n; k++)
                if (k < i || k >= j)
                    c[lc++] = a[k];
                else
                    b[lb++] = a[k];
            sort(b, b + lb);
            sort(c, c + lc);
            b[lb] = 1e9;
            c[lc] = 0;
            for (int k = 0; k < t; k++) {
                if (k >= lc)
                    break;
                if (c[lc - 1 - k] > b[k])
                    b[k] = c[lc - 1 - k];
                else
                    break;
            }
            cur = 0;
            for (int k = 0; k < lb; k++)
                cur += b[k];
            ans = max(ans, cur);
        }
    cout << ans;
}