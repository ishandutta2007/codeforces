#include<bits/stdc++.h>
using namespace std;

int main() {
    cin.tie(0);
    ios::sync_with_stdio(0);
    int n, x, y;
    cin >> n >> x >> y;
    ++n;
    vector<int> a(n);
    bitset<200005> bs;
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
        bs[a[i]] = true;
    }
    bitset<200005> exi;
    for (int i = 0; i + 1 < n; ++i) {
        exi |= bs;
        bs >>= a[i + 1] - a[i];
    }
    int lim = 500005;

    vector<int> ans(lim, -1);
    for (int i = 1; i < 200005; ++i) {
        if (exi[i]) {
            for (int j = i + y; j < lim; j += i + y) {
                ans[j] = (i + y) * 2;
            }
        }
    }
    int q;
    cin >> q;
    for (int i = 0; i < q; ++i) {
        int l;
        cin >> l;
        cout << ans[l / 2] << (i < q - 1 ? ' ' : '\n');
    }

    return 0;
}