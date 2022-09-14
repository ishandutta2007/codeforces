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
#ifdef ONPC
    freopen("a.in", "r", stdin);
#endif
    ios_base::sync_with_stdio(0); cin.tie(0);
    int t, n, k1, k2, m1, m2, x;
    cin >> t;
    rep(z, t) {
        cin >> n >> k1 >> k2;
        m1 = m2 = 0;
        rep(i, k1) {
            cin >> x;
            m1 = max(m1, x);
        }
        rep(i, k2) {
            cin >> x;
            m2 = max(m2, x);
        }
        if (m1 > m2)
            cout << "YES\n";
        else
            cout << "NO\n";
    }
}