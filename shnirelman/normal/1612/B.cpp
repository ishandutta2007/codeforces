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
const int N = 1e6 + 113;
const int K = 1e5 + 113;
const int M = 1e9 + 7;
const int A = 26;

/*

*/

mt19937 rnd(3666);

void solve() {
    int n, a, b;
    cin >> n >> a >> b;

    vector<int> p(n);
    for(int i = 0; i < n; i++) {
        p[i] = n - i;
    }

    if(b < n / 2 || a > n / 2 + 1) {
        cout << -1 << endl;
        return;
    }

    swap(p[n / 2 - 1], p[n - a]);

    int i1 = -1, i2 = -1;
    for(int i = 0; i < n; i++) {
        if(p[i] == b) {
            i1 = i;
        }
    }

    i2 = n / 2;

    assert(i1 != -1 && i2 != -1);

    swap(p[i1], p[i2]);

    int mn = n;
    for(int i = 0; i < n / 2; i++)
        mn = min(mn, p[i]);

    int mx = 0;
    for(int i = n / 2; i < n; i++)
        mx = max(mx, p[i]);

    if(mn != a || mx != b) {
        cout << -1 << endl;
//        cout << mn << ' ' << mx << endl;
        return;
    }

//    cout << "---";
    for(int i = 0; i < n; i++)
        cout << p[i] << ' ';
    cout << endl;
}

signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int t = 1;
    cin >> t;

    while(t--)
        solve();
}