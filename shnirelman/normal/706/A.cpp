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
const int A = 1e6 + 13;
const int N = 2000 + 13;
//const int N = 10;
const int B = 400;
const int LOGN = 20;

mt19937 rnd(2);

int sum(int a, int b) {
    a += b;
    return (a < M ? a : a - M);
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


int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int a, b;
    cin >> a >> b;

    int n;
    cin >> n;

    ld ans = INF;
    for(int i = 0; i < n; i++) {
        int x, y, v;
        cin >> x >> y >> v;

        int dx = x - a, dy = y - b;

        ans = min(ans, ld(sqrt(dx * dx + dy * dy) / v));
    }

    cout << setprecision(20) << fixed << ans << endl;
}