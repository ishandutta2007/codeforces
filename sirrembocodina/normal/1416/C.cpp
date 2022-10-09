#include <bits/stdc++.h>

//#define int long long

using namespace std;

int32_t main() {
    ios_base::sync_with_stdio(false);
    int n = 300000;
    scanf("%d", &n);
    vector<int> a(n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &a[i]);
        //a[i] = rand() * rand() % 1000000000;
    }
    long long ans = 0;
    long long res = 0;
    for (int b = 29; b >= 0; b--) {
        long long cnt0 = 0, cnt1 = 0;
        if (b >= 10) {
            vector<int> cnt(1 << (30 - b));
            for (int i = 0; i < n; i++) {
                int x = a[i] >> b;
                if (x % 2) {
                    cnt1 += cnt[x ^ 1];
                } else {
                    cnt0 += cnt[x ^ 1];
                }
                cnt[x]++;
            }
        } else {
            unordered_map<int, int> m;
            for (int i = 0; i < n; i++) {
                int x = a[i] >> b;
                if (x % 2) {
                    cnt1 += m[x ^ 1];
                } else {
                    cnt0 += m[x ^ 1];
                }
                m[x]++;
            }
        }
        if (cnt0 > cnt1) {
            ans ^= 1 << b;
        }
        res += min(cnt0, cnt1);
    }
    cout << res << " " << ans << endl;
}