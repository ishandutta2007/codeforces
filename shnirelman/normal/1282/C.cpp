#include <bits/stdc++.h>

#define f first
#define s second

using namespace std;
using li = long long;

/*
1
7 17 1 6
1 1 0 1 0 0 0
1 7 0 11 10 15 10

0 1 1
0 1 7
*/

void solve() {
    int n, T, x, y;
    cin >> n >> T >> x >> y;

    vector<pair<int, bool>> a(n);
    for(int i = 0; i < n; i++) {
        int c;
        cin >> c;

        a[i].s = (c == 1);
    }

    for(int i = 0; i < n; i++) {
        cin >> a[i].f;
    }

    sort(a.begin(), a.end());

    vector<pair<int, int>> s(n + 1, {0, 0});
    for(int i = 1; i <= n; i++) {
        s[i] = s[i - 1];
        if(a[i - 1].s)
            s[i].s++;
        else
            s[i].f++;
    }

    int ca = 0, cb = 0;

    for(int i = 0; i < n; i++) {
        if(a[i].s)
            cb++;
        else
            ca++;
    }

    int ans = 0;
    for(int i = 0; i <= n; i++) {
        int res = 0;
        int t = (i < n ? a[i].f - 1 : T);
        li sum = s[i].f * 1ll * x + s[i].s * 1ll * y;

        if(sum > t) {
            continue;
        }

        t -= sum;

        res += i;

        int ca1 = min(ca - s[i].f, t / x);

        res += ca1;
        t -= ca1 * x;

        int cb1 = min(cb - s[i].s, t / y);

        res += cb1;

        ans = max(ans, res);
    }

    cout << ans << endl;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int t;
    cin >> t;

    while(t--)
        solve();
}