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
const int LOGN = 20;
const int K = 22;
const int M = 998244353;//1e9 + 7;
//const int A = 26;
const ld eps = 1e-8;

mt19937 rnd(45768);

/*
*/

int qr = 0;
vector<int> A = {2, 2, 2, 2, 0};

int query(int i, int j, int k) {
    cout << "? " << i + 1 << ' ' << j + 1 << ' ' << k + 1 << endl;
//    int res = max({A[i], A[j], A[k]}) - min({A[i], A[j], A[k]});
//    cout << res << endl;
//    cout << "qr " << qr++ << endl;
    int res;
    cin >> res;

    return res;
}

void answer(int i, int j) {
    cout << "! " << i + 1 << ' ' << j + 1 << endl;
}

void solve() {
    int n;
    cin >> n;

    int v = 1, u = 2;
    int cur = query(0, v, u);
    for(int i = 3; i < n; i++) {
        int r1 = query(0, v, i);
        int r2 = query(0, u, i);

        if(r1 >= r2 && r1 > cur) {
            u = i;
            cur = r1;
        } else if(r2 >= r1 && r2 > cur) {
            v = i;
            cur = r2;
        }
    }

//    cout << v << ' ' << u << endl;

    int w = 1;
    while(w == v || w == u)
        w++;

    int r1 = query(v, u, w);
    int r2 = query(0, v, w);
    int r3 = query(0, u, w);

    vector<int> ans;
    if(r1 < cur)
        ans.push_back(0);
    if(r2 < cur)
        ans.push_back(u);
    if(r3 < cur)
        ans.push_back(v);

    answer(ans[0], (ans.size() == 1 ? ans[0] : ans[1]));
}

signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int t = 1;
    cin >> t;

    while(t--)
        solve();


}