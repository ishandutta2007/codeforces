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
const int M = 998244353;
const int N = 2e5 + 13;
const int LOGN = 30;

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

void solve() {
    int n, q;
    cin >> n >> q;

    vector<int> a(n);
    for(int i = 0; i < n; i++) {
        cin >> a[i];
    }

    if(q >= n) {
        for(int i = 0; i < n; i++)
            cout << '1';
        cout << endl;
        return;
    }

//    vector<bool> b(n, false);
//
//    for(int i = 0; i < n; i++) {
//        if(a[i] <= q) {
//            b[i] = true;
//        }
//    }

    int l = 0, r = n + 1;
    while(r - l > 1) {
        int m = (l + r) / 2;

        int x = q;
        for(int i = n - m; i < n; i++) {
            if(a[i] > x)
                x--;
        }

        if(x < 0)
            r = m;
        else
            l = m;
    }

    vector<bool> b(n, false);
    for(int i = 0; i < n - l; i++) {
        if(a[i] <= q)
            b[i] = true;
    }

    for(int i = n - l; i < n; i++)
        b[i] = true;

    for(auto x : b)
        cout << x;
    cout << endl;

//    vector<int> cnt(n + 2, 0);
//    int x = q;
//    for(int i = n - 1; i >= 0; i--) {
//        if(b[i]) {
//            if(a[i] > n)
//                cnt[n + 1]++;
//            else
//                cnt[a[i]]++;
//        } else {
//            if(cnt[])
//        }
//    }
}

signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int t = 1;
    cin >> t;

    while(t--)
        solve();
}