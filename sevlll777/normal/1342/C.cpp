// #define _GLIBCXX_DEBUG

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
#define ld long double
#define pb push_back
#define str string
using namespace std;
const int M = 998244353;

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int t1;
    cin >> t1;
    while (t1--) {
        int a, b, q;
        cin >> a >> b >> q;
        if (a > b) {
            swap(a, b);
        }
        while (q--) {
            int l, r;
            cin >> l >> r;
            if (r - l + 1 <= 428) {
                int ans = 0;
                for (int x = l; x <= r; x++) {
                    if (x % a % b != x % b % a) {
                        ans++;
                    }
                }
                cout << ans << ' ';
            } else {
                int ans = r - l + 1;
                int g = a / gcd(a, b);
                while (l % b != 0) {
                    if (l % a % b == l % b % a) {
                        ans--;
                    }
                    l++;
                }
                while (r % b != b - 1) {
                    if (r % a % b == r % b % a) {
                        ans--;
                    }
                    r--;
                }
                int blc = (r - l + 1) / b;
                int s = (l - l % b) / b;
                int e = s + blc - 1;
                ans -= (e / g - (s-1) / g) * b;
                cout << ans << ' ';
            }

        }
        cout << '\n';
    }


}