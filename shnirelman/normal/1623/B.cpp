#include <bits/stdc++.h>

#define f first
#define s second
//#define int li

using namespace std;
using li = long long;
using ld = long double;
using pii = pair<int, int>;

const int INF = 1e9 + 13;
const li INF64 = 2e18 + 13;
const int N = 2e5;
const int LOGN = 20;
const int K = 11;
const int M = 998244353;//1e9 + 7;
const int A = 26;

int sum(int a, int b) {
    a += b;
    return (a >= M ? a - M : a);
}

/*

*/

void solve() {
    int n;
    cin >> n;

    vector<pii> a(n);
    set<pii> st;
    for(int i = 0; i < n; i++) {
        cin >> a[i].f >> a[i].s;
    }

    for(int i = 0; i < n; i++) {
        int lf = -1, rg = -1;
        for(int j = 0; j < n; j++)
            if(i != j) {
                if(a[j].f == a[i].f && a[j].s < a[i].s && (lf == -1 || a[j].s - a[j].f > a[lf].s - a[lf].f))
                    lf = j;

                if(a[j].s == a[i].s && a[j].f > a[i].f && (rg == -1 || a[j].s - a[j].f > a[rg].s - a[rg].f))
                    rg = j;
            }

        int d = (lf != -1 ? a[lf].s + 1 : (rg != -1 ? a[rg].f - 1 : a[i].f));

        cout << a[i].f << ' ' << a[i].s << ' ' << d << '\n';
    }

    cout << '\n';
}

signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int t = 1;
    cin >> t;

    while(t--)
        solve();
}