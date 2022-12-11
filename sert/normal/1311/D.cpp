#pragma GCC diagnostic ignored "-Wunused-result"
#include <bits/stdc++.h>
#define all(v) v.begin(), v.end()
using namespace std;
typedef long long ll;
int D = 0;

vector<vector<int>> dd;

void init(int mx) {
    dd.resize(mx + 1);
    for (int i = 1; i <= mx; i++) {
        dd[i].clear();
        for (int x = 1; x * x <= i; x++) {
            if (i % x) continue;
            dd[i].push_back(x);
            if (x * x != i) dd[i].push_back(i / x);
        }
        sort(dd[i].begin(), dd[i].end());
    }
}

void solve() {
    int a, b, c;
    cin >> a >> b >> c;
    int a1, b1, c1, bst = 100500;
    for (int bb = 1; bb <= 20000; bb++) {
        int cur = abs(bb - b);
        if (D == 0 && cur >= bst) continue;
        int aa, cc;

        if (c <= bb) {
            cur += bb - c;
            cc = bb;
        } else {
            int cc1 = c - c % bb;
            int cc2 = cc1 + bb;
            int d1 = abs(cc1 - c);
            int d2 = abs(cc2 - c);
            if (d1 < d2) cc = cc1;
            else cc = cc2;
            cur += min(d1, d2);
        }
        if (D == 0 && cur >= bst) continue;

        if (a >= bb) {
            cur += a - bb;
            aa = bb;
        } else {
            int pos = upper_bound(dd[bb].begin(), dd[bb].end(), a) - dd[bb].begin();

            int s1 = abs(dd[bb][pos] - a);
            int s2 = abs(dd[bb][pos - 1] - a);
            if (s1 < s2) aa = dd[bb][pos];
            else aa = dd[bb][pos - 1];
            cur += min(s1, s2);
        }

        if (cur >= bst) continue;
        bst = cur;
        a1 = aa;
        b1 = bb;
        c1 = cc;                
    }
    cout << bst << "\n" << a1 << " " << b1 << " " << c1 << "\n";
}

int main() {
#ifdef SERT
    D = 1;
#endif
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    init(20000);
    int t;
    cin >> t;
    while (t--) solve();
}