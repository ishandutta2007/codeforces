//#define _GLIBCXX_DEBUG
#include <bits/stdc++.h>

#define f first
#define s second
//#define int li

using namespace std;
using li = long long;
using ld = long double;
using pii = pair<int, int>;
using pli = pair<li, li>;
//using matr

const li INF = 2e18 + 13;
const int N = 2e5 + 13;
const int M = 998244353;
const int B = 300;
//const int A = 26;
const ld e = 1e-8;
const int LOGN = 20;
const int K = 170;

mt19937 rnd(0);

/*
*/

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

int p[N], r[N];

int A(int n, int k) {
    if(k > n)
        return 0;

    return mul(p[n], r[n - k]);
}

void solve() {
    int n;
    cin >> n;

    vector<int> a(n);
    for(int i = 0; i < n; i++) {
        cin >> a[i];
    }

    sort(a.rbegin(), a.rend());

    if(a[1] == a[0]) {
        cout << p[n] << '\n';
        return;
    }

    if(a[0] - a[1] >= 2) {
        cout << 0 << '\n';
        return;
    }

    int cnt = 0;
    for(int i = 1; i < n; i++)
        cnt += (a[i] == a[1]);

    int ans = p[n];
    for(int i = 0; i < n; i++) {
        ans = dif(ans, mul(p[n - cnt - 1], A(n - i - 1, cnt)));
    }

    cout << ans << '\n';
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    p[0] = 1;
    r[0] = 1;
    for(int i = 1; i < N; i++) {
        p[i] = mul(p[i - 1], i);
        r[i] = pow2(p[i], M - 2);
    }

    int t;
    cin >> t;

    while(t--)
        solve();
}