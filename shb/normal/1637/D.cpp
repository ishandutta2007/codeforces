#include <bits/stdc++.h>

using namespace std;

typedef long long LL;
typedef pair<int,int> pii;

bool f[110][20010];

int main() {
    ios::sync_with_stdio(false);
    int T;
    cin >> T;
    while(T--) {
        int n;
        cin >> n;
        vector<int> a(n + 1), b(n + 1);
        LL sum_sqr = 0;
        LL sum = 0;
        for (int i = 1; i <= n; i++) {
            cin >> a[i];
            sum_sqr += a[i] * a[i];
            sum += a[i];
        }
        for (int i = 1; i <= n; i++) {
            cin >> b[i];
            sum_sqr += b[i] * b[i];
            sum += b[i];
        }
        for (int i = 0; i <= n; i++) {
            for (int j = 0; j <= sum; j++) {
                f[i][j] = false;
            }
        }
        f[0][0] = true;
        for (int i = 1; i <= n; i++) {
            for (int j = 0; j <= sum; j++) {
                if (j >= a[i]) f[i][j] |= f[i - 1][j - a[i]];
                if (j >= b[i]) f[i][j] |= f[i - 1][j - b[i]];
            }
        }
        LL ans = (n - 1) * sum_sqr;
        LL best_split;
        for (int i = sum / 2; i >= 0; i--) {
            if (f[n][i]) {
                best_split = i;
                break;
            }
        }
        LL g = best_split * best_split + (sum - best_split) * (sum - best_split);
        g -= sum_sqr;
        ans += g;
        cout << ans << '\n'; 
    }
}