#pragma GCC diagnostic ignored "-Wunused-result"
#include <bits/stdc++.h>
#define all(v) v.begin(), v.end()
using namespace std;
typedef long long ll;

void solve() {
    int n, m, x;
    int sum = 0;
    cin >> n >> m;
    vector<int> num(101, 0);
    for (int i = 0; i < n; i++) {
        cin >> x;
        sum += x;
        int cur = sum;
        int ans = 0;

        for (int j = (int)num.size() - 1; cur > m && j > 0; j--) {
            if (num[j] == 0) continue;
            if (cur - j * num[j] <= m) {
                ans += (cur - m + j - 1) / j;
                cur = m;
            } else {
                ans += num[j];
                cur -= j * num[j];
            }
        }
        cout << ans << " ";
        num[x]++;
    }
    cout << "\n";
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    solve();
#ifdef MADE_BY_SERT
    int T = 2;
    for (int i = 1; i < T; i++) solve();    
#endif
}