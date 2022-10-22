#include <bits/stdc++.h>

#define f first
#define s second

using namespace std;
using li = long long;
using ld = long double;
using pii = pair<int, int>;

const int INF = 1e9 + 13;
const int M = 1e9 + 7;
const int N = 1e5 + 13;
const int LOGN = 20;
const int A = 27;

void solve() {
    int n;
    cin >> n;

    vector<int> a(n);
    for(int i = 0; i < n; i++) {
        cin >> a[i];
    }

    li ans = (a[0] + a[1]) * 1ll * n;
    int mnx = a[0], mny = a[1];
    li cur = a[0] + a[1];
    for(int i = 2; i < n; i++) {
        cur += a[i];
        if(i % 2 == 0) {
            mnx = min(mnx, a[i]);

            ans = min(ans, cur + mnx * 1ll * (n - i / 2 - 1) + mny * 1ll * (n - i / 2));
        } else {
            mny = min(mny, a[i]);
            ans = min(ans, cur + mnx * 1ll * (n - i / 2 - 1) + mny * 1ll * (n - i / 2 - 1));
        }
    }

    cout << ans << endl;
}

int main() {
    int t;
    cin >> t;

    while(t--)
        solve();
}