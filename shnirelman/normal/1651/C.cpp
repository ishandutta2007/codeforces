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
const int N = 3e5 + 13;
const int LOGN = 40;
const int K = 22;
const int M = 998244353;//1e9 + 7;
const int A = 26;
const ld eps = 1e-8;

mt19937 rnd(45768);

/*
*/

void solve() {
    int n;
    cin >> n;

    vector<int> a(n), b(n);
    for(int i = 0; i < n; i++)
        cin >> a[i];

    for(int j = 0; j < n; j++)
        cin >> b[j];

    vector<int> a1 = {0, n - 1, 0}, a2 = a1;
    for(int i = 0; i < n; i++) {
        if(abs(a[0] - b[i]) < abs(a[0] - b[a1[2]]))
            a1[2] = i;
    }

    for(int i = 0; i < n; i++) {
        if(abs(a[n - 1] - b[i]) < abs(a[n - 1] - b[a2[2]]))
            a2[2] = i;
    }

    vector<int> b1 = {0, n - 1, 0}, b2 = a1;
    for(int i = 0; i < n; i++) {
        if(abs(b[0] - a[i]) < abs(b[0] - a[b1[2]]))
            b1[2] = i;
    }

    for(int i = 0; i < n; i++) {
        if(abs(b[n - 1] - a[i]) < abs(b[n - 1] - a[b2[2]]))
            b2[2] = i;
    }

    li ans = INF64;
    for(int i1 = 0; i1 < 3; i1++) {
        for(int i2 = 0; i2 < 3; i2++) {
            for(int j1 = 0; j1 < 3; j1++) {
                for(int j2 = 0; j2 < 3; j2++) {
                    set<pii> st;
                    st.emplace(0, a1[i1]);
                    st.emplace(n - 1, a2[i2]);
                    st.emplace(b1[j1], 0);
                    st.emplace(b2[j2], n - 1);

                    li res = 0;
                    for(auto p : st) {
                        res += abs(a[p.f] - b[p.s]);
                    }

                    ans = min(ans, res);
                }
            }
        }
    }

    cout << ans << endl;
}

signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int t = 1;
    cin >> t;

    while(t--)
        solve();
}