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
    int x;
    vector<int> a(3);
    cin >> x >> a[0] >> a[1] >> a[2];

    x--;

    if(a[x] != 0 && a[a[x] - 1] != 0)
        cout << "YES" << endl;
    else
        cout << "NO" << endl;
}

signed main() {
//    ios::sync_with_stdio(0);
//    cin.tie(0);

    int t = 1;
    cin >> t;

    while(t--)
        solve();
}