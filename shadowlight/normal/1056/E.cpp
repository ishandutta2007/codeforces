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
vector <ll> hashs, pows;

ll gh(ll l, ll r) {
    if (!l) {
        return hashs[r];
    }
    return (hashs[r] - pows[r - l + 1] * hashs[l - 1] % INF + INF) % INF;
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
    string s, t;
    cin >> s >> t;
    int n = s.size();
    int m = t.size();
    hashs.resize(m);
    pows.resize(m);
    hashs[0] = t[0] - 'a' + 1;
    pows[0] = 1;
    for (ll i = 1; i < m; i++) {
        hashs[i] = (hashs[i - 1] * Q + t[i] - 'a' + 1) % INF;
        pows[i] = pows[i - 1] * Q % INF;
    }
    ll a = 0, b = 0;
    for (char c : s) {
        if (c == '0') {
            a++;
        } else {
            b++;
        }
    }
    int res = 0;
    for (ll len = 1; len <= m; len++) {
        if (len * a >= m || (m - len * a) % b) continue;
        ll x = len, y = (m - len * a) / b;
        int pos = 0;
        bool can = true;
        ll ha = -1, hb = -1;
        for (int i = 0; i < n; i++) {
            if (s[i] == '0') {
                if (ha == -1) {
                    ha = gh(pos, pos + x - 1);
                } else if (ha != gh(pos, pos + x - 1)) {
                    can = false;
                }
                pos += x;
            } else {
                if (hb == -1) {
                    hb = gh(pos, pos + y - 1);
                } else if (hb != gh(pos, pos + y - 1)) {
                    can = false;
                }
                pos += y;
            }
            if (!can) break;
        }
        if (x == y && ha == hb) {
            can = false;
        }
        res += can;
    }
    cout << res << "\n";
}