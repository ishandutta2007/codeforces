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
// #define int long long
#define ld long double
using namespace std;
const int M = 1000000007;

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        string a, b;
        cin >> a >> b;
        vector<int> ans;
        for (int i = n - 1; i >= 0; i--) {
            if (a[i] != b[i]) {
                if (a[i] != a[0]) {
                    ans.pb(1);
                    a[0] = a[i];
                }
                ans.pb(i + 1);
                string a2 = a;
                for (int j = 0; j <= i; j++) {
                    a2[j] = a[i - j];
                    if (a2[j] == '0') {
                        a2[j]++;
                    } else {
                        a2[j]--;
                    }
                }
                a = a2;
            }
        }
        cout << ans.size() << ' ';
        for (auto x : ans) cout << x << ' ';
        cout << '\n';
    }

}