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

//const bool debug_out = false;
const bool debug_out = true;

const int INF = 1e9 + 13;
const li INF64 = 1e18 + 13;
const int N = 2e5 + 13;
const int LOGN = 30;
const int K = 22;
const int M = 1e9 + 7;
const int A = 26;
const ld eps = 1e-15;

/*
*/


void solve() {
    string s;
    cin >> s;

    sort(s.begin(), s.end());

    cout << s << endl;
}

signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int t = 1;
    cin >> t;

    while(t--)
        solve();
}