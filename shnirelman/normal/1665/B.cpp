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
const int N = 2e5 + 13;
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

/*
*/

void solve() {
    int n;
    cin >> n;

    vector<int> a(n);
    map<int, int> mp;
    for(int i = 0; i < n; i++) {
        cin >> a[i];

        mp[a[i]]++;
    }

    int mx = 0;
    for(auto p : mp)
        mx = max(mx, p.s);

    int ans = 0;
    while(mx < n) {
        ans++;
        int d = min(n - mx, mx);
        ans += d;
        mx += d;
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