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
//const int M = 1e9 + 7;
const int M = 998244353;
const int A = 26;
const ld eps = 1e-8;

mt19937 rnd(45768);

/*
*/

int mul(int a, int b) {
    return a * 1ll * b % M;
}

void solve() {
    int n, m, k, q;
    cin >> n >> m >> k >> q;

    map<int, int> mxr, mxc;
    for(int i = 0; i < q; i++) {
        int x, y;
        cin >> x >> y;

        mxr[x] = i;
        mxc[y] = i;
    }

    int mnr = INF, mnc = INF;
    if(mxr.size() == n)
        for(auto p : mxr)
            mnr = min(mnr, p.s);
    else
        mnr = -1;

    if(mxc.size() == m)
        for(auto p : mxc)
            mnc = min(mnc, p.s);
    else
        mnc = -1;

//    int cnt = 0;
    set<int> st;
    for(auto p : mxr) {
//        cnt += (p.s > mnc);
        if(p.s >= mnc)
            st.insert(p.s);
    }

    for(auto p : mxc) {
//        cnt += (p.s >= mnr);
        if(p.s >= mnr)
            st.insert(p.s);
    }

//    cout << mnr << ' ' << mnc << ' ' << cnt << endl;

    int ans = 1;
    for(int i = 0; i < st.size(); i++)
        ans = mul(ans, k);

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