#include <bits/stdc++.h>
using namespace std;
constexpr int N = 1<<20;
constexpr int B = 20;
int n, mx[N], mn[N], pre[N], suf[N], a[N];
int main() {
    ios::sync_with_stdio(false);
    cout.tie(0);
    cin >> n;
    for (int i = 1; i <= n; i ++)
        cin >> a[i]; 

    int ans = 0;
    for (int id = 0; id < 2; id ++) {
        for (int b = B - 1, mask = 1<<B; b >= 0; b --) {
            for (int i = 1; i <= n; i ++) {
                pre[i] = (pre[i-1] ^ a[i]) & mask; // [b+1, +) 
            }
            for (int i = 1, j = 1; i <= n; i = j) {
                if (not (a[i] >> b & 1)) {
                    j ++; continue;
                }
                while (j <= n and (a[j] >> b & 1)) j ++;
                // [i, j)         
                for (int x = i - 1; x < j; x ++) {
                    if (x%2 == id)
                        mn[pre[x]] = N, mx[pre[x]] = -1;
                }
                for (int x = i - 1; x < j; x ++) {
                    if (x%2 == id){
                        mn[pre[x]] = min(mn[pre[x]], x);
                        mx[pre[x]] = max(mx[pre[x]], x);
                    }
                }
                for (int x = i - 1; x < j; x ++) {
                    if (x%2 == id)
                        ans = max(ans, mx[pre[x]] - mn[pre[x]]);
                }
            }
            mask = mask ^ (1<<b);
        }
    }
    cout << ans << "\n";
}