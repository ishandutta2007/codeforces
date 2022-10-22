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
const int N = 3500 + 13;
const int LOGN = 10;
const int K = 11;
const int M = 1e9 + 7;
const int A = 26;

/*
4
1 2 3 4
1
1 5
*/

int n, m, k;
int a[N];
bool b[N];
int s[N];

bool is(int x) {
    for(int i = 0; i <= m; i++)
        b[i] = false;

    for(int i = 0; i <= m; i++) {
        if(a[i] >= x || a[n - (m - i) - 1] >= x)
            b[i] = true;
    }

    for(int i = 0; i <= m; i++) {
        s[i + 1] = s[i] + b[i];
    }

    for(int i = 0; i <= k; i++) {
        if(s[m - k + i + 1] - s[i] == m - k + 1)
            return true;
    }
    return false;
}

void solve() {
    cin >> n >> m >> k;

    m--;
    k = min(m, k);

    for(int i = 0; i < n; i++) {
        cin >> a[i];
    }

    int l = 0, r = INF;
    while(r - l > 1) {
        int mid = (l + r) / 2;

        if(is(mid))
            l = mid;
        else
            r = mid;
    }

    cout << l << endl;
}

signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int t = 1;
    cin >> t;

    while(t--)
        solve();
}