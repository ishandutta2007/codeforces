#include <bits/stdc++.h>

#define f first
#define s second
#define int li

using namespace std;
using li = long long;
using ld = long double;
using pii = pair<int, int>;

const int INF = 1e9 + 13;
const li INF64 = 2e18 + 13;
const int N = 2e5 + 13;
const int LOGN = 20;
const int K = 11;
const int M = 998244353;//1e9 + 7;
const int A = 26;

int sum(int a, int b) {
    return (a + b) % M;
//    a += b;
//    return (a >= M ? a - M : a);
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

    if(k % 2)
        return mul(pw, n);
    else
        return pw;
}
/*
*/

int query(int i, int j) {
    cout << "? " << i + 1 << ' ' << j + 1 << endl;
    int res;
    cin >> res;
    return res;
}

void solve() {
    int n;
    cin >> n;

    vector<int> p(n);
    int mx = 0;
    for(int i = 1; i < n; i++) {
        int r1 = query(mx, i), r2 = query(i, mx);

        if(r2 > r1) {
            p[i] = r2;
        } else {
            p[mx] = r1;
            mx = i;
        }
    }

    p[mx] = n;
    cout << "! " << endl;
    for(int i = 0; i < n; i++) {
        cout << p[i] << ' ';
    }
    cout << endl;
}

signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int t = 1;
//    cin >> t;

    while(t--)
        solve();
}