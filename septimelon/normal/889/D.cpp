#include <algorithm>
#include <chrono>
#include <cmath>
#include <ctime>
#include <iomanip>
#include <iostream>
#include <iterator>
#include <map>
#include <queue>
#include <random>
#include <set>
#include <stack>
#include <string>
#include <utility>
#include <vector>

using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;

const ll MOD = 1000000007;
const ld EPS = 1e-11;
const ll INFL = 1e16;
const int INF = 2e9 + 7;

mt19937 rnd((unsigned)chrono::steady_clock::now().time_since_epoch().count());

ll gcd(ll a, ll b) {
    if (a == 0 || b == 0) {
        return a + b;
    }
    return gcd(b, a % b);
}

pair<ll, ll> test(ll cx, ll cy, vector<ll> x, vector<ll> y, ll sx, ll sy, ll n) {
    sx -= n * cx;
    sy -= n * cy;
    for (int i = 0; i < n; ++i) {
        x[i] -= cx;
        y[i] -= cy;
    }

    ll a = 0 - sy, b = sx;
    if (a < 0 || a == 0 && b < 0) {
        a *= -1;
        b *= -1;
    }

    vector<ll> c(n);
    for (int i = 0; i < n; ++i) {
        c[i] = a * x[i] + b * y[i];
    }
    sort(c.begin(), c.end());

    for (int i = 0; i < n; ++i) {
        if (c[i] != 0 - c[n - i - 1]) {
            return { 0, 0 };
        }
    }

    return { a / gcd(a, b), b / gcd(a, b) };
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    ll n;
    cin >> n;
    vector<ll> x(n), y(n);
    ll sx = 0, sy = 0;
    for (int i = 0; i < n; ++i) {
        cin >> x[i] >> y[i];;
        x[i] *= 2;
        y[i] *= 2;
        sx += x[i];
        sy += y[i];
    }
    
    for (int i = 0; i < n; ++i) {
        if (sx == x[i] * n && sy == y[i] * n) {
            sx -= x[i];
            sy -= y[i];
            --n;
            x.erase(x.begin() + i);
            y.erase(y.begin() + i);
            --i;
        }
    }
    for (int i = 0; i < n; ++i) {
        for (int j = i + 1; j < n; ++j) {
            if ((x[i] + x[j]) * n == sx * 2LL && (y[i] + y[j]) * n == sy * 2LL) {
                sx -= x[i] + x[j];
                sy -= y[i] + y[j];
                n -= 2;
                x.erase(x.begin() + j);
                x.erase(x.begin() + i);
                y.erase(y.begin() + j);
                y.erase(y.begin() + i);
                --i;
                break;
            }
        }
    }

    if (n == 0) {
        cout << "-1\n";
        return 0;
    }

    vector<pair<ll, ll>> degs;
    if (n % 2 == 1) {
        for (int i = 0; i < n; ++i) {
            pair<ll, ll> ca = test(x[i], y[i], x, y, sx, sy, n);
            if (ca.first != 0 || ca.second != 0) {
                degs.push_back(ca);
            }
        }
    }
    else {
        for (int i = 1; i < n; ++i) {
            pair<ll, ll> ca = test((x[0] + x[i]) / 2, (y[0] + y[i]) / 2, x, y, sx, sy, n);
            if (ca.first != 0 || ca.second != 0) {
                degs.push_back(ca);
            }
        }
    }

    if (degs.size() == 0) {
        cout << "0\n";
        return 0;
    }

    sort(degs.begin(), degs.end());
    int ans = 1;
    for (int i = 1; i < degs.size(); ++i) {
        if (degs[i] != degs[i - 1]) {
            ++ans;
        }
    }
    cout << ans << "\n";

    return 0;
}