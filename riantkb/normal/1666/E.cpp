// #pragma GCC target("avx2")
#pragma GCC optimize("O3")
// #pragma GCC optimize("unroll-loops")
#include<bits/stdc++.h>
using namespace std;

using P = pair<int, int>;
const int M = 1000000007;


int main() {
    cin.tie(0);
    ios::sync_with_stdio(0);
    long long l;
    int n;
    cin >> l >> n;
    vector<long long> a(n);
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }
    a.push_back(l);
    long long min_ok = 0, min_ng = M;
    while (min_ok + 1 < min_ng) {
        long long m = (min_ok + min_ng) / 2;
        long long lef = 0;
        bool f = true;
        for (int i = 0; i < n; ++i) {
            long long nex = max(lef + m, a[i]);
            if (nex > a[i + 1]) {
                f = false;
                break;
            }
            lef = nex;
        }
        if (f) {
            min_ok = m;
        }
        else {
            min_ng = m;
        }
    }

    long long max_ng = min_ok - 1, max_ok = M;
    while (max_ng + 1 < max_ok) {
        long long m = (max_ng + max_ok) / 2;
        long long lef_min = 0;
        long long lef_max = 0;
        bool f = true;
        for (int i = 0; i < n; ++i) {
            long long nex_min = max(lef_min + min_ok, a[i]);
            long long nex_max = min(lef_max + m, a[i + 1]);
            if (nex_min > nex_max) {
                f = false;
                break;
            }
            if (i == n - 1 && lef_max + m < l) {
                f = false;
                break;
            }
            lef_min = nex_min;
            lef_max = nex_max;
        }
        if (f) {
            max_ok = m;
        }
        else {
            max_ng = m;
        }
    }
    // cerr << min_ok << ' ' << max_ok << '\n';
    {
        vector<long long> lef_mins(n + 1);
        vector<long long> lef_maxs(n + 1);
        for (int i = 0; i < n; ++i) {
            lef_mins[i + 1] = max(lef_mins[i] + min_ok, a[i]);
            lef_maxs[i + 1] = min(lef_maxs[i] + max_ok, a[i + 1]);
        }
        long long now = l;
        vector<long long> ans;
        ans.push_back(now);
        for (int i = n - 1; i >= 0; --i) {
            long long mi = now - max_ok;
            now = max(mi, lef_mins[i]);
            ans.push_back(now);
        }
        reverse(ans.begin(), ans.end());
        for (int i = 0; i < n; ++i) {
            cout << ans[i] << ' ' << ans[i + 1] << '\n';
        }
    }



    return 0;
}