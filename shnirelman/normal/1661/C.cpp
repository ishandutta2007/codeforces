#include <bits/stdc++.h>

#define f first
#define s second

using namespace std;
using li = long long;
using ld = long double;
using pii = pair<int, int>;

const int INF = 2e9 + 13;
const li INF64 = 2e18 + 13;
//const int M = 998244353;
const int M = 32768;
const int N = 3e5 + 13;
const int LOGN = 20;

int sum(int a, int b) {
    a += b;
    return (a >= M ? a - M : a);
}

int dif(int a, int b) {
    return sum(a, M - b);
}

int mul(int a, int b) {
    return a * 1ll * b % M;
}

int pow2(int n, int k) {
    if(k == 0)
        return 1;

    int pw = pow2(n, k / 2);
    pw = mul(pw, pw);

    return (k % 2 == 0 ? pw : mul(pw, n));
}

int inv(int n) {
    return pow2(n, M - 2);
}

mt19937 rnd(0);

int a[N];

bool is(int n, int x, li m) {
    li c1 = (m + 1) / 2, c2 = m / 2;

    for(int i = 0; i < n; i++) {
        int y = x - a[i];
        li d = min(y / 2ll, c2);
        y -= d * 2;
        c2 -= d;
        c1 -= y;
    }

    return (c1 >= 0 && c2 >= 0);
}

void solve() {
    int n;
    cin >> n;

    int mx = 0;
    for(int i = 0; i < n; i++) {
        cin >> a[i];
        mx = max(mx, a[i]);
    }

    li ans = INF64;
    for(int x = mx; x <= mx + 1; x++) {
        li l = -1, r = INF64;
        while(r - l > 1) {
            li m = (l + r) / 2;

            if(is(n, x, m))
                r = m;
            else
                l = m;
        }
        ans = min(ans, r);
    }

    cout << ans << endl;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int t = 1;
    cin >> t;

    while(t--)
        solve();
}