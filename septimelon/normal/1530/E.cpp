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

const ll MOD = 998244353;
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

vector<ll> fact, rfact;

void prep() {
    fact.assign(200001, 1);
    for (int i = 1; i < 200001; ++i) {
        fact[i] = i;
        mul(fact[i], fact[i - 1]);
    }
    rfact.assign(200001, 1);
    rfact.back() = todeg(fact.back(), -1);
    for (int i = 200000; i > 0; --i) {
        rfact[i - 1] = i;
        mul(rfact[i - 1], rfact[i]);
    }
}

ll C(int n, int k) {
    if (n < 0 || k < 0 || n < k) {
        return 0;
    }
    ll ans = fact[n];
    mul(ans, rfact[k]);
    mul(ans, rfact[n - k]);
    return ans;
}

void printRest(vector<int>& cc) {
    int cha{ 'a' };
    while (cha <= 'z') {
        if (cc[cha] == 0) {
            ++cha;
            continue;
        }
        cout << (char)cha;
        --cc[cha];
    }
    cout << "\n";
}

void solve() {
    string s;
    cin >> s;
    int n = s.size();
    vector<int> cc('z' + 1, 0);
    for (int i = 0; i < n; ++i) {
        char a{ s[i] };
        ++cc[a];
    }

    int c1 = 'a';
    while (cc[c1] == 0) {
        ++c1;
    }

    if (cc[c1] == n) { /// case 0
        for (int i = 0; i < n; ++i) {
            cout << (char)c1;
        }
        cout << "\n";
        return;
    }

    int uniq{ c1 };
    while (uniq <= 'z' && cc[uniq] != 1) {
        ++uniq;
    }

    if (uniq <= 'z') { /// case 1
        cout << (char)uniq;
        --cc[uniq];
        printRest(cc);
        return;
    }

    int c2 = c1 + 1;
    while (cc[c2] == 0) {
        ++c2;
    }

    if (cc[c1] <= n - cc[c1] + 2) { /// case 2
        cout << (char)c1;
        --cc[c1];
        while (cc[c1] > 0) {
            cout << (char)c1;
            --cc[c1];
            while (c2 <= 'z' && cc[c2] == 0) {
                ++c2;
            }
            if (c2 <= 'z') {
                cout << (char)c2;
                --cc[c2];
            }
        }
        printRest(cc);
        return;
    }

    if (cc[c1] + cc[c2] == n) { /// case 3
        cout << (char)c1;
        for (int i = 0; i < cc[c2]; ++i) {
            cout << (char)c2;
        }
        for (int i = 1; i < cc[c1]; ++i) {
            cout << (char)c1;
        }
        cout << "\n";
        return;
    }

    cout << (char)c1; /// case 4
    --cc[c1];
    cout << (char)c2;
    --cc[c2];
    while (cc[c1] > 0) {
        cout << (char)c1;
        --cc[c1];
    }
    int c3 = c2 + 1;
    while (cc[c3] == 0) {
        ++c3;
    }
    cout << (char)c3;
    --cc[c3];
    printRest(cc);
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    //    freopen("input.txt", "r", stdin);
    //    freopen("output.txt", "w", stdout);

    //prep();

    int t;
    cin >> t;
    for (int q = 0; q < t; ++q) {
        solve();
    }

    return 0;
}