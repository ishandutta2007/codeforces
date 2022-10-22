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
#include <cassert>
#include <assert.h>

//#pragma GCC optimize("O3")

using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;

const ll MOD = 1000000007;
const ld EPS = 1e-11;
const ll INFL = 2e18;
const int INF = 2e9 + 7;
const ld PI = acos(-1);
const ld E = exp(1);

mt19937 rnd((unsigned)chrono::steady_clock::now().time_since_epoch().count());

void add(ll& a, ll b) {
    a += b;
    if (a >= MOD) {
        a -= MOD;
    }
}

void mul(ll& a, ll b) {
    a = (a * b) % MOD;
}

ll todeg(ll x, ll d) {
    if (d < 0) {
        d += MOD - 1;
    }
    if (d == 0) {
        return 1;
    }
    ll ans{ todeg(x, d / 2) };
    mul(ans, ans);
    if (d & 1) {
        mul(ans, x);
    }
    return ans;
}

void ask(int cv, int n, vector<int>& u, vector<int>& v) {
    cout << "? " << cv + 1 << endl;
    for (int i = 1; i <= n; ++i) {
        int d;
        cin >> d;
        if (d == 1) {
            u.push_back(cv + 1);
            v.push_back(i);
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    //    freopen("input.txt", "r", stdin);
    //    freopen("output.txt", "w", stdout);

    int n;
    cin >> n;

    cout << "? 1" << endl;
    vector<int> d(n);
    int cc{ 0 }, cn{ 0 };
    for (int i = 0; i < n; ++i) {
        cin >> d[i];
        if (d[i] & 1) {
            ++cn;
        }
        else {
            ++cc;
        }
    }

    vector<int> u, v;
    if (cc <= cn) {
        for (int i = 1; i < n; ++i) {
            if (d[i] == 1) {
                u.push_back(1);
                v.push_back(i + 1);
            }
            if ((d[i] & 1) == 0) {
                ask(i, n, u, v);
            }
        }
    }
    else {
        for (int i = 1; i < n; ++i) {
            if (d[i] & 1) {
                ask(i, n, u, v);
            }
        }
    }

    cout << "!" << endl;
    for (int i = 0; i < u.size(); ++i) {
        cout << u[i] << " " << v[i] << endl;
    }

    return 0;
}