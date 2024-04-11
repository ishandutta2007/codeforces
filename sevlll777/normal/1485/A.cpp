#include <bits/stdc++.h>

#define pb push_back
#define int long long
#define all(x) x.begin(), x.end()
#define ld long double
using namespace std;

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int t;
    cin >> t;
    while (t--) {
        int a, b;
        cin >> a >> b;
        int oh = 0;
        if (b == 1) {
            b = 2;
            oh = 1;
        }
        int ans = 1e18;
        for (int e = (b == 1); e <= 1000; e++) {
            int aa = a;
            int kek = 0;
            while (aa) {
                kek++;
                aa = aa / b;
            }
            ans = min(ans, kek + e);
            b++;
        }
        cout << oh+ans;
        cout << '\n';
    }

}