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
const int N = 2e5 + 13;
const int LOGN = 20;
const int K = 22;
const int M = 998244353;//1e9 + 7;
//const int A = 26;
const ld eps = 1e-8;

mt19937 rnd(45768);

/*
*/

signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n;
    cin >> n;

    vector<pii> a(n);
    vector<string> s(n);
    for(int i = 0; i < n; i++) {
        cin >> s[i];
        cin >> a[i].f;
        a[i].s = i;
    }

    sort(a.begin(), a.end());

    for(int i = 0; i < n; i++) {
        if(a[i].f > i) {
            cout << -1 << endl;
            return 0;
        }
    }

    vector<int> ord;
    for(int i = 0; i < n; i++) {
        ord.insert(ord.begin() + a[i].f, a[i].s);
    }

    vector<int> h(n);
    for(int i = 0; i < n; i++) {
        h[ord[i]] = n - i;
    }

    for(int i = 0; i < n; i++) {
        cout << s[a[i].s] << ' ' << h[a[i].s] << endl;
    }
}