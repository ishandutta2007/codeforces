#include <bits/stdc++.h>

#define f first
#define s second
//#define x first
//#define y second
//#define int li
#define err if(debug_out)cout

using namespace std;
using li = long long;
using ld = long double;
using pii = pair<int, int>;
using pld = pair<ld, ld>;

const int INF = 1e9 + 13;
const li INF64 = 1e18 + 13;
const int N = 2500 + 13;
const int LOGN = 30;
const int K = 22;
const int M = 1e9 + 7;
const int A = 26;
const ld eps = 1e-15;

mt19937 rnd(45768);

/*
*/

void solve() {
    string s;
    cin >> s;

    vector<int> c(2, 0);
    for(int i = 0; i < s.size(); i++) {
        c[s[i] - '0']++;
    }

    if(c[0] == c[1])
        cout << c[0] - 1 << '\n';
    else
        cout << min(c[0], c[1]) << '\n';
}

signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int t = 1;
    cin >> t;

    while(t--)
        solve();
}