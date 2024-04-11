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

const ll INF = 1e18 + 7;
const int MAXN = 1e6 + 7;
const double EPS = 1e-8;

vector <ll> st;

void init() {
    st.push_back(0);
    while (true) {
        st.push_back(4 * st.back() + 1);
        if (st.back() > INF) {
            st.back() = INF;
            break;
        }
    }
}

void solve() {
    ll n, k;
    cin >> n >> k;
    ll l = 0, r = 0;
    ll now = 1;
    while (n) {
        l += now, r += now;
        ll nxt = 2 * now + 1;
        ll good = 4 * now - nxt;
        now = nxt;
        if (k < l) {
            cout << "NO\n";
            return;
        }
        n--;
        if (n >= st.size()) {
            cout << "YES " << n << "\n";
            return;
        }
        if (n && (INF - r) / st[n] < good) {
            cout << "YES  " << n << "\n";
            return;
        }
        r += st[n] * good;
        if (k <= r) {
            cout << "YES " << n << "\n";
            return;
        }
    }
    cout << "NO\n";
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
    init();
    int t;
    cin >> t;
    for (int i = 0; i < t; i++) {
        solve();
    }
}