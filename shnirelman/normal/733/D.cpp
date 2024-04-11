//#define _GLIBCXX_DEBUG
#include <bits/stdc++.h>

#define f first
#define s second
//#define int li

using namespace std;
using li = long long;
using ld = long double;
using pii = pair<int, int>;
using vint = vector<int>;
using matr = vector<vint>;

const int INF = 1e9 + 13;
const li INF64 = 1e18 + 13;
const int N = 2e5 + 13;
const int M = 1e9 + 9;
const ld eps = 1e-6;
const int K = 103;

/*
3 1
1 0 0
*/


signed main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n;
    cin >> n;

    vector<int> a(n), b(n), c(n);
    for(int i = 0; i < n; i++) {
        cin >> a[i] >> b[i] >> c[i];
    }

    map<pii, pii> mp;
    int ans = 0;
    vector<int> res;
    for(int i = 0; i < n; i++) {
//        int mn = min({a[i], b[i], c[i]});
        if(a[i] > b[i])
            swap(a[i], b[i]);
        if(b[i] > c[i])
            swap(b[i], c[i]);
        if(a[i] > b[i])
            swap(a[i], b[i]);

        if(ans < a[i]) {
            ans = a[i];
            res = {i};
        }

        if(mp.count({b[i], c[i]})) {
            pii p = mp[{b[i], c[i]}];
            int a1 = a[i] + p.f;
            int mn = min(a1, b[i]);
            if(mn > ans) {
                ans = mn;
                res = {p.s, i};
            }
        }

        mp[{a[i], b[i]}] = max(mp[{a[i], b[i]}], pii(c[i], i));
        mp[{a[i], c[i]}] = max(mp[{a[i], c[i]}], pii(b[i], i));
        mp[{b[i], c[i]}] = max(mp[{b[i], c[i]}], pii(a[i], i));
    }

    cout << res.size() << endl;
    for(auto i : res)
        cout << i + 1 << ' ';
    cout << endl;
}