#include <iostream>
#include <iomanip>
#include <cstdio>
#include <vector>
#include <algorithm>
#include <cmath>
#include <cstring>
#include <cassert>
#include <string>
#include <set>
#include <map>
#include <random>
#include <bitset>
#include <string>
#include <unordered_set>
#include <unordered_map>
#include <deque>
#include <queue>
#define rep(i, n) for (int i = 0; i < (n); i++)
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()

using namespace std;
using ll = long long;
using ul = unsigned long long;
using ld = long double;

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    ll t, p, f, c1, c2, w1, w2;
    cin >> t;
    rep(z, t) {
        cin >> p >> f >> c1 >> c2 >> w1 >> w2;
        if (w1 > w2) {
            swap(w1, w2);
            swap(c1, c2);
        }
        ll ans = 0;
        rep(i, c1 + 1) {
            if (i * w1 > p)
                continue;
            ll q = min(c1 - i, f / w1);
            ans = max(ans, i + q + min(c2, (p - i * w1) / w2 + (f - q * w1) / w2));
        }
        cout << ans << '\n';
    }
}