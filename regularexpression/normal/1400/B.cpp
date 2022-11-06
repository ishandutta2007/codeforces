#include<bits/stdc++.h>
using namespace std;
#define int long long

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int t;
    cin >> t;
    while (t--) {
        int p, f, cnts, cntw, s, w;
        cin >> p >> f >> cnts >> cntw >> s >> w;
        if (s > w) {
            swap(s, w);
            swap(cnts, cntw);
        }
        int ans = 0;
        for (int takes = 0; takes <= min(cnts, p / s); ++takes) {
            int takew = min(cntw, (p - s * takes) / w);
            int rests = cnts - takes, restw = cntw - takew;
            int takes_f = min(rests, f / s);
            int takew_f = min(restw, (f - s * takes_f) / w);
            ans = max(ans, takes + takew + takes_f + takew_f);
        }
        cout << ans << '\n';
    }
    return 0;
}