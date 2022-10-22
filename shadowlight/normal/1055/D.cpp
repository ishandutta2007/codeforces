#include <iostream>
#include <tuple>
#include <sstream>
#include <vector>
#include <cmath>
#include <ctime>
#include <bitset>
#include <cassert>
#include <cstdio>
#include <queue>
#include <set>
#include <map>
#include <fstream>
#include <cstdlib>
#include <string>
#include <cstring>
#include <algorithm>
#include <numeric>
#define ll long long

#define TASKNAME ""

using namespace std;

const ll INF = 1e9 + 7;
const int MAXN = 1e6 + 7;
const double EPS = 1e-8;
const ll Q = 31;

vector <string> a, b;

vector <ll> zfunc(string s) {
    ll n = s.size();
    vector <ll> z(n, 0);
    ll l = -1, r = -1;
    for (ll i = 1; i < n; i++) {
        if (r >= i) {
            z[i] = min(r - i + 1, z[i - l]);
        }
        while (i + z[i] < n && s[i + z[i]] == s[z[i]]) {
            z[i]++;
        }
        if (i + z[i] - 1 > r) {
            l = i, r = i + z[i] - 1;
        }
    }
    return z;
}

int main() {
    #ifdef MY
        freopen("input.txt", "r", stdin);
        //freopen("output.txt", "w", stdout);
    #else
        //freopen(TASKNAME".in", "r", stdin);
        //freopen(TASKNAME".out", "w", stdout);
        ios_base::sync_with_stdio(false);
        cin.tie(0);
        cout.tie(0);
    #endif // MY
    int n;
    cin >> n;
    a.resize(n);
    b.resize(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    for (int i = 0; i < n; i++) {
        cin >> b[i];
    }
    string kek, pek;
    ll l = -1, r = -1, id = -1, len = -1, h = -1;
    vector <ll> lbad(n, 0), rbad(n, 0);
    for (int i = 0; i < n; i++) {
        int sz = a[i].size();
        int lt = INF, rt = -INF;
        for (int j = 0; j < sz; j++) {
            if (a[i][j] != b[i][j]) {
                lt = min(lt, j);
                rt = max(rt, j);
            }
        }
        lbad[i] = lt, rbad[i] = rt;
        if (lt != INF) {
            len = rt - lt + 1;
            id = i;
            l = lt, r = rt;
        }
    }
    while (true) {
        bool can = true;
        if (!lbad[id]) break;
        char c = a[id][lbad[id] - 1];
        for (ll i = 0; i < n; i++) {
            if (lbad[i] == INF) continue;
            if (!lbad[i] || a[i][lbad[i] - 1] != c) {
                can = false;
                break;
            }
        }
        if (!can) break;
        for (ll i = 0; i < n; i++) {
            if (lbad[i] != INF) {
                lbad[i]--;
            }
        }
    }
    while (true) {
        bool can = true;
        if (rbad[id] == (ll) a[id].size() - 1) break;
        char c = a[id][rbad[id] + 1];
        for (ll i = 0; i < n; i++) {
            if (rbad[i] == -INF) continue;
            if (rbad[i] == (ll) a[i].size() - 1 || a[i][rbad[i] + 1] != c) {
                can = false;
                break;
            }
        }
        if (!can) break;
        for (ll i = 0; i < n; i++) {
            if (rbad[i] != -INF) {
                rbad[i]++;
            }
        }
    }
    l = lbad[id], r = rbad[id], len = rbad[id] - lbad[id] + 1;
    kek = a[id].substr(l, len);
    pek = b[id].substr(l, len);
    for (ll i = 0; i < n; i++) {
        ll pos = -1;
        string st = kek + "#" + a[i];
        auto z = zfunc(st);
        for (ll j = 0; j < (ll) a[i].size(); j++) {
            if (z[j + kek.size() + 1] == len) {
                pos = j;
                break;
            }
        }
        if (pos == -1 && lbad[i] != INF) {
            cout << "NO\n";
            return 0;
        }
        if (pos == -1) continue;
        if (pos != lbad[i]) {
            cout << "NO\n";
            return 0;
        }
        if (pos + len - 1 != rbad[i]) {
            cout << "NO\n";
            return 0;
        }
        if (b[i].substr(pos, len) != pek) {
            cout << "NO\n";
            return 0;
        }
    }
    cout << "YES\n";
    cout << kek << "\n" << pek;
}