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
    while (t--) {
        int l, r, m;
        cin >> l >> r >> m;
        if (m == 1919102) cout << "kek";
        for (int a = l; a <= r; a++) {
            if (m >= a) {
                int d = m % a;
                if (d <= r - l) {
                    cout << a << ' ' << l + d << ' ' << l;
                    break;
                }
            }
            int dd = a - m % a;
            if (dd <= r - l) {
                cout << a << ' ' << l << ' ' << l+dd;
                break;
            }

        }


        cout << '\n';
    }
}