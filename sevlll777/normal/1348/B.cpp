#include <iostream>
#include <iomanip>
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
#include <random>
#include <queue>
#include <bitset>

#define int long long
#define dbl long double
#define pb push_back
#define str string
using namespace std;
const int M = 998244353;

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int t;
    cin >> t;
    while (t--) {
        int n, k;
        cin >> n >> k;
        set<int> sss;
        for (int i = 0; i < n; i++) {
            int a;
            cin >> a;
            sss.insert(a);
        }
        if (sss.size() > k) {
            cout << "-1\n";
        } else {
            int kek = 1;
            while (sss.size() != k) {
                if (sss.find(kek) == sss.end()) {
                    sss.insert(kek);
                }
                kek++;
            }
            vector<int> ans;
            for (int _ = 0; _ < n; _++) {
                for (auto p : sss) ans.pb(p);
            }
            cout << ans.size() << '\n';
            for (auto yy : ans) cout << yy << ' ';
            cout << '\n';
        }

    }
}