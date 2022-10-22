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
    int n;
    cin >> n;

    vector<int> k(n);
    for(int i = 0; i < n; i++)
        cin >> k[i];

    vector<int> h(n);
    for(int i = 0; i < n; i++) {
        cin >> h[i];
    }

    stack<pii> st;
    for(int i = 0; i < n; i++) {
        int l = k[i] - h[i] + 1, r = k[i];
        while(!st.empty()) {
            int lf = st.top().f;
            int rg = st.top().s;
            if(l < lf) {
                st.pop();
            } else {
                if(l > rg) {
                    st.push({l, r});
                } else {
                    st.top().s = r;
                }
                break;
            }
        }
        if(st.empty())
            st.push({l, r});
    }

    li ans = 0;
    while(!st.empty()) {
        int d = st.top().s - st.top().f + 1;
        ans += d * 1ll * (d + 1) / 2;
        st.pop();
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