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
        vector<int> negativ, positiv;
        bool zero = false;
        while (n--) {
            int a;
            cin >> a;
            if (a < 0) {
                negativ.pb(a);
            } else if (a > 0) {
                positiv.pb(a);
            } else {
                zero = true;
            }
        }
        sort(positiv.rbegin(), positiv.rend());
        sort(negativ.begin(), negativ.end());
        if (positiv.empty()) {
            if (zero || negativ.size() < 5) {
                cout << "0\n";
            } else {
                sort(negativ.rbegin(), negativ.rend());
                cout << negativ[0] * negativ[1] * negativ[2] * negativ[3] * negativ[4] << '\n';
            }
        } else {
            int ans = -1e18;
            if (zero) ans = 0;
            for (int skok = 1; skok <= 5; skok++) {
                if (positiv.size() >= skok && negativ.size() >= 5 - skok) {
                    int kek = 1;
                    for (int H = 0; H < skok; H++) kek *= positiv[H];
                    for (int H = 0; H < 5 - skok; H++) kek *= negativ[H];
                    ans = max(ans, kek);
                }
            }
            cout << ans << '\n';
        }
    }

}