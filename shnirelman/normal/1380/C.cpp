#include <bits/stdc++.h>

#define f first
#define s second

using namespace std;
using li = long long;
using ld = long double;
using pii = pair<int, int>;

const int INF = 1e9;
const int M = 1e9 + 7;
const int N = 2e5 + 13;

int a[N];

void solve() {
    int n, x;
    cin >> n >> x;

    for(int i = 0; i < n; i++)
        cin >> a[i];

    sort(a, a + n);
    reverse(a, a + n);

    int ans = 0;
    for(int i = 0; i < n; i++) {
        int mn = a[i];
        bool fl = false;
        for(int j = 1; j + i <= n; j++)
            if(mn * 1ll * j >= x) {
                ans++;
                i += j - 1;
                fl = true;
                break;
            } else if(i + j < n) {
                mn = a[i + j];
            } else
                break;

        if(!fl)
            break;
    }

    cout << ans << endl;
}

int main() {
    int t = 1;
    cin >> t;

    while(t--)
        solve();
}