#include <bits/stdc++.h>

#define f first
#define s second

using namespace std;
using li = long long;
using ld = long double;
using pii = pair<int, int>;

const int INF = 2e9 + 13;
const int M = 998244353;
const int N = 2e5 + 13;


void solve() {
    int n;
    cin >> n;

    vector<int> a(n);
    vector<int> cnt(2, 0);
    for(int i = 0; i < n; i++) {
        cin >> a[i];
        cnt[a[i] % 2]++;
    }

    vector<vector<int>> suf(n + 1, vector<int>(2, n));
    for(int i = n - 1; i >= 0; i--) {
        suf[i] = suf[i + 1];
        int x = a[i] % 2;
        if(suf[i][x] == n || a[suf[i][x]] > a[i])
            suf[i][x] = i;
    }

    vector<int> mn(2, -1);
    vector<pii> res;
    for(int i = 0; i < n; i++) {
        int x = a[i] % 2;
        int y = x ^ 1;

        if(mn[y] != -1) {
            res.emplace_back(mn[y], i);
            a[i] = a[mn[y]];
        } else if(suf[i + 1][x] != n) {
            res.emplace_back(i, suf[i + 1][x]);
            a[i] = a[suf[i + 1][x]];
        }

//        cout << "for " << i << ' ' << a[i] << ' ' << mn[x] << ' ' << mn[y] << endl;

        x = a[i] % 2;
        if(mn[x] == -1 || a[mn[x]] < a[i])
            mn[x] = i;
    }

//    if(cnt[0] == 0 || cnt[1] == 0) {
//        cout << n - 1 << '\n';
//        for(int i = 0; i < n - 1; i++)
//            cout << i + 1 << ' ' << n << '\n';
//        return;
//    }
//
//    int x = (a[n - 1] % 2) ^ 1;
//
//    int mx = -1;
//    vector<pii> res;
//    for(int i = 0; i < n; i++) {
//        if(a[i] % 2 == x) {
//            if(mx == -1 || a[mx] < a[i])
//                mx = i;
//        } else {
//            res.emplace_back(mx, i);
//            a[i] = a[mx];
//        }
//    }
//
//    int mn = n - 1;
//    for(int i = n - 2; i >= 0; i--) {
//        if(a[i] > a[i + 1]) {
//            res.emplace_back(i, i + 1);
//        }
//    }

    cout << res.size() << '\n';
    for(auto p : res)
        cout << p.f + 1 << ' ' << p.s + 1 << '\n';
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int t = 1;
    cin >> t;

    while(t--)
        solve();
}