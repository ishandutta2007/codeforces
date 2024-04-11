#include <bits/stdc++.h>

#define f first
#define s second
//#define int li

using namespace std;
using li = long long;
using ld = long double;
using pii = pair<int, int>;

const int INF = 1e9 + 13;
const int N = 2e5 + 13;
const int M = 1e9 + 7;
const int A = 26;

int a[N], b[N];

void solve() {
    int n;
    cin >> n;

    for(int i = 0; i < n; i++) {
        cin >> a[i] >> b[i];
    }

    int l = 0, r = n + 1;
    while(r - l > 1) {
        int m = (l + r) / 2;

        int cur = 0;
        for(int i = 0; i < n; i++) {
            if(b[i] >= cur && a[i] >= m - cur - 1) {
                cur++;
            }
        }

        if(cur >= m)
            l = m;
        else
            r = m;
    }

    cout << l << endl;
}

signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int t;
    cin >> t;

    while(t--)
        solve();
}