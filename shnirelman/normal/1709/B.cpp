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

void solve() {
    int n, q;
    cin >> n >> q;

    vector<int> a(n);
    for(int i = 0; i < n; i++)
        cin >> a[i];

    vector<li> p1(n, 0), p2(n, 0);

    for(int i = 1; i < n; i++) {
        p2[i] = p2[i - 1] + max(0, a[i] - a[i - 1]);
        p1[i] = p1[i - 1] + max(0, a[i - 1] - a[i]);
    }

    for(int i = 0; i < q; i++) {
        int s, t;
        cin >> s >> t;

        s--;
        t--;

        if(s < t) {
            cout << p1[t] - p1[s] << '\n';
        } else {
            cout << p2[s] - p2[t] << '\n';
        }
    }
}

signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int t = 1;
//    cin >> t;

    while(t--)
        solve();
}