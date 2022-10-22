#include <bits/stdc++.h>

#define f first
#define s second

using namespace std;
using li = long long;
using ld = long double;
using pii = pair<int, int>;

const int INF = 2e9 + 13;
const li INF64 = 2e18 + 13;
const int M = 998244353;
const int A = 1e6 + 13;
const int N = 2e5 + 13;
const int B = 400;
const int LOGN = 20;

mt19937 rnd(2);

void solve() {
    int n;
    cin >> n;

    vector<pii> a(n);
    int mxx = 0, mnx = 0, mxy = 0, mny = 0;
    for(int i = 0; i < n; i++) {
        cin >> a[i].f >> a[i].s;

        mnx = min(mnx, a[i].f);
        mxx = max(mxx, a[i].f);

        mny = min(mny, a[i].s);
        mxy = max(mxy, a[i].s);
    }

    cout << (mxx - mnx + mxy - mny) * 2 << endl;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int t = 1;
    cin >> t;

    while(t--)
        solve();
}