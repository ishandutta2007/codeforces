#include <bits/stdc++.h>

#define f first
#define s second

using namespace std;
using li = long long;
using ld = long double;
using pii = pair<int, int>;

const int INF = 1e9 + 13;
const li INF64 = 1e18 + 13;
const int N = 2e5 + 13;
const int K = 9;
const int M = 2e6 + 9;
const int LOGN = 20;

void solve() {
    int n, q;
    cin >> n >> q;

    vector<int> a(n);
    li sum = 0;
    for(int i = 0; i < n; i++) {
        cin >> a[i];
        sum += a[i];
    }

    vector<int> t(n, -1);

    int x = -1, T = -2;
    for(int i = 0; i < q; i++) {
        int tp;
        cin >> tp;

        if(tp == 1) {
            int ind, y;
            cin >> ind >> y;

            ind--;

            sum -= (T < t[ind] ? a[ind] : x);
            sum += y;
            a[ind] = y;
            t[ind] = i;
        } else {
            cin >> x;
            sum = x * 1ll * n;
            T = i;
        }

        cout << sum << '\n';
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int t = 1;
//    cin >> t;

    while(t--)
        solve();
}