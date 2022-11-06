#include<bits/stdc++.h>
using namespace std;

#define x first
#define y second
#define pb push_back
#define mp make_pair

#define all(a) (a).begin(), (a).end()
#define sz(a) (int)(a).size()

#define ll long long
#define ld long double
#define int long long

int f(int st, int len) {
    len = min(len, st);
    return st * len - len * (len - 1) / 2;
}

int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int a, b, c, d;
    cin >> a >> b >> c >> d;
    int ans = (b - a + 1) * (c - b + 1) * (d - c + 1);
    for (int k = c; k <= d; k++) {
        if (a + b > k) continue;
        int nans = 0;
        if (a + c <= k) {
            int r = min(b, k - c);
            nans += (r - a + 1) * (c - b + 1);
            if (r + 1 <= b) nans += f(c - b, b - r);
        } else nans += f(min(k - a, c) - b + 1, b - a + 1);
        ans -= nans;
    }
    cout << ans;
    return 0;
}