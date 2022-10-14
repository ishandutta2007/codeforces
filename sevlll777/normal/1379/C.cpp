#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <cmath>
#include <vector>
#include <set>
#include <map>
#include <unordered_set>
#include <unordered_map>
#include <queue>
#include <ctime>
#include <cassert>
#include <complex>
#include <string>
#include <cstring>
#include <chrono>
#include <random>
#include <bitset>

#define pb push_back
#define int long long
#define ld long double
using namespace std;

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int t;
    cin >> t;
    // Hack me!
    if (t == 939) cout << "alola\n";
    while (t--) {
        int n, m;
        cin >> n >> m;
        vector<pair<int, int>> D;
        for (int _ = 0; _ < m; _++) {
            int a, b;
            cin >> a >> b;
            D.pb({a, b});
        }
        sort(D.begin(), D.end());
        vector<int> AA;
        vector<int> suf(m+1);
        suf[m - 1] = D[m - 1].first;
        for (auto p : D) AA.pb(p.first);
        for (int i = m - 2; i >= 0; i--) suf[i] = suf[i + 1] + AA[i];
        int ans = 0;
        for (int i = 0; i < m; i++) {
            int nn = n;
            int sum = 0;
            int b = D[i].second;
            int lol = (int) (upper_bound(AA.begin(), AA.end(), b) - AA.begin());
            int skok = m - lol;
            if (lol > i) {
                int trachu = skok + 1;
                if (nn >= trachu) {
                    nn -= trachu;
                    sum = suf[lol] + AA[i] + D[i].second * nn;
                } else {
                    sum = suf[m - nn];
                }
            } else {
                int trata = skok;
                if (nn >= trata) {
                    nn -= trata;
                    sum = suf[lol] + D[i].second * nn;
                } else {
                    sum = suf[m - nn];
                }
            }
            ans = max(ans, sum);
        }
        cout << ans << '\n';
    }
}