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
    ll t, m, d, w;
    cin >> t;
    rep(z, t) {
        cin >> m >> d >> w;
        ll g = w / __gcd(d - 1, w);
        if (m > d)
            swap(m, d);
        cout << (m / g) * (m / g - 1) / 2 * (g - m % g) + (m / g + 1) * (m / g) / 2 * (m % g) << '\n';
    }
}