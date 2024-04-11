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

const int INF = 2e9 + 13;
const li INF64 = 1e18 + 13;
const int N = 2e5 + 13;
const int LOGN = 20;
const int K = 22;
const int M = 1e9 + 7;
//const int M = 998244353;
const int A = 26;
const ld eps = 1e-8;

mt19937 rnd(45768);

/*
*/

void solve() {
    string s;
    cin >> s;

    set<char> st;
    for(int i = 0; i < 6; i++) {
        if('a' <= s[i] && s[i] <= 'z') {
            st.insert(s[i]);
        } else if(st.count(tolower(s[i])) == 0) {
            cout << "NO" << endl;
            return;
        }
    }

    cout << "YES" << endl;
}

signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int t = 1;
    cin >> t;

    while(t--)
        solve();
}