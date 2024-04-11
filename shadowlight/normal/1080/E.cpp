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
const ll MAXN = 1e6 + 7;
const double EPS = 1e-8;
const ll Q = 31;

ll manaker(vector <ll> a) {
//    cout << "A: ";
//    for (ll x : a) {
//        cout << x << " ";
//    }
//    cout << "\n";
    vector <ll> b(1, -1);
    ll n = a.size();
    for (ll i = 0; i < n; i++) {
        b.push_back(a[i]);
        b.push_back(-1);
    }
    a = b;
    ll l = -1, r = -1;
    n = 2 * n + 1;
    vector <ll> man(n, 0);
    for (ll i = 0; i < n; i++) {
        if (i <= r) {
            man[i] = min(r - i + 1, man[r + l - i]);
        }
        while (i - man[i] >= 0 && i + man[i] < n && a[i - man[i]] == a[i + man[i]]) {
            man[i]++;
        }
        if (i + man[i] - 1 > r) {
            l = i - man[i] + 1;
            r = i + man[i] - 1;
        }
    }
    ll sum = 0;
    for (ll i = 0; i < n; i++) {
        if (a[i] < -1) continue;
        if (i % 2 == 0) {
            sum += man[i] / 2;
        } else {
            sum += (man[i] + 1) / 2;
        }
    }
    return sum;
}

bool isPal(vector <int> cnt) {
    int ch = 0;
    for (int x : cnt) {
        if (x % 2) {
            ch++;
        }
    }
    return ch < 2;
}

ll get_hash(vector <int> cnt) {
    ll h = 0;
    for (ll x : cnt) {
        h = (h * Q + x + 1) % INF;
    }
    return h;
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
    int n, m;
    cin >> n >> m;
    vector <vector <char> > a(n, vector <char> (m));
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> a[i][j];
        }
    }
    ll res = 0;
    vector <ll> st(Q, 0);
    st[0] = 1;
    for (ll i = 1; i < Q; i++) {
        st[i] = st[i - 1] * MAXN % INF;
    }
    for (int i = 0; i < m; i++) {
        vector <vector <int> > cnt(n, vector <int> (Q, 0));
        vector <int> odd(n, 0);
        vector <ll> h(n, 0);
        for (int j = i; j < m; j++) {
            bool can = true;
            for (int k = 0; k < n; k++) {
                int c = a[k][j] - 'a';
                cnt[k][c]++;
                h[k] = (h[k] + st[c]) % INF;
                if (cnt[k][c] % 2) {
                    odd[k]++;
                } else {
                    odd[k]--;
                }
            }
            ll last = -2;
            vector <ll> ha;
            for (ll k = 0; k < n; k++) {
                if (odd[k] >= 2) {
                    ha.push_back(last--);
                } else {
                    ha.push_back(h[k]);
                }
            }
//            for (ll x : ha) {
//                cout << x << " ";
//            }
//            cout << "\n";
//            cout << i << " " << j << " " << manaker(ha) << "\n";
            res += manaker(ha);
        }
    }
    cout << res;
}