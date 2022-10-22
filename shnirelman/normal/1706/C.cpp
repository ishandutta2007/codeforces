#include <bits/stdc++.h>

#define f first
#define s second
//#define int li

using namespace std;
using li = long long;
using ld = long double;
using pii = pair<int, int>;
using vi = vector<int>;
using matr = vector<vi>;

const int INF = 1e9 + 13;
const li INF64 = 4e18 + 13;
//const int M = 1e9 + 7;
//const int M = 998244353;
const int N = 1e5 + 13;
const int LOGN = 30;

int M;

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

mt19937 rnd(45567);

int a[N];
li pref[N], suf[N];

void solve() {
    int n;
    cin >> n;

    for(int i = 0; i <= n + 2; i++) {
        pref[i] = suf[i] = 0;
    }

    for(int i = 0; i < n; i++)
        cin >> a[i];

    if(n % 2 == 1) {
        li ans = 0;
        for(int i = 1; i < n - 1; i += 2) {
            ans += max({0, a[i - 1] - a[i] + 1, a[i + 1] - a[i] + 1});
        }

        cout << ans << endl;
        return;
    }

    for(int i = 1; i < n - 1; i += 2) {
        pref[i] = pref[i + 1] = pref[i - 1] + max({0, a[i - 1] - a[i] + 1, a[i + 1] - a[i] + 1});
    }

    for(int i = n - 2; i >= 1; i -= 2) {
        suf[i] = suf[i - 1] = suf[i + 1] + max({0, a[i - 1] - a[i] + 1, a[i + 1] - a[i] + 1});
    }

//    cout << "-----------" << endl;
//    for(int i = 0; i < n; i++)
//        cout << pref[i] << ' ';
//    cout << endl;
//    for(int i = 0; i < n; i++)
//        cout << suf[i] << ' ';
//    cout << endl;


    li ans = suf[1];

    for(int i = 1; i < n - 1; i++) {
        ans = min(ans, pref[i] + suf[i + 1]);
    }
//    vector<li> ans(2, 0);
//    for(int i = 1; i < n - 1; i++) {
//        ans[i % 2] += max({0, a[i - 1] - a[i] + 1, a[i + 1] - a[i] + 1});
//    }

    cout << ans << endl;
}

signed main() {
//    ios::sync_with_stdio(0);
//    cin.tie(0);

    int t = 1;
    cin >> t;

    while(t--)
        solve();
}