#include <bits/stdc++.h>

using namespace std;

using ll = long long;
using ull = unsigned long long;
using ld = long double;

#define all(a) (a).begin(), (a).end()

#define prev prev228

// mt19937 rnd(chrono::steady_clock::now().time_since_epoch().count());

template<typename T1, typename T2> 
inline void chkmin(T1& x, const T2& y) {
    if (y < x) x = y;
}

template<typename T1, typename T2>
inline void chkmax(T1& x, const T2& y) {
    if (x < y) x = y;
}

ll x, k;

const int INF = 1e5;
ll divs[INF];
int topDivs = 0;
vector<int> myDivs[INF];
int cnt = 0;

void genDivs() {
    for (ll i = 1; i * i <= x; ++i) {
        if (x % i == 0) {
            divs[topDivs++] = i;
            if (i * i != x) {
                divs[topDivs++] = x / i;
            }
        }
    }
    sort(divs, divs + topDivs);
    for (int i = 0; i < topDivs; ++i) {
        for (int j = 0; j <= i; ++j) {
            if (divs[i] % divs[j]) continue;
            myDivs[i].push_back(j);
        }
    }
}

void rec(int pos, ll k) {
    if (cnt == INF) return;
    if (k < 0) return;
    if (pos == 0) k = 0;
    if (k == 0) {
        if (cnt > 0) cout << " ";
        cout << divs[pos];
        ++cnt;
    }
    for (auto j : myDivs[pos]) {
        rec(j, k - 1);
        if (cnt == INF) return;   
    }
}

signed main() {
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    cout.precision(20), cout.setf(ios::fixed);
    cin >> x >> k;
    if (x == 1) {
        cout << x << endl;
    } else {
        genDivs();       
        rec(topDivs - 1, k);
    }
    return 0;
}