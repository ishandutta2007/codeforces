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

//int dp[M];
//
//int calc(int x) {
//    if(x == 0 || dp[x] >= 0)
//        return dp[x];
//
//    if(dp[x] == -2)
//        return INF;
//
//    cout << "calc " << x << endl;
//
//    dp[x] = -2;
//
//    return dp[x] = min(calc((x + 1) % M), calc((x * 2) % M));
//}

//int cnt[M];

void solve() {
    int n;
    cin >> n;



//    for(int i = 0; i < M; i++)
//        dp[i] = -1;

    for(int i = 0; i < n; i++) {
        int x;
        cin >> x;

        if(x == 0) {
            cout << 0 << ' ';
            continue;
        }

        int res = INF;
        for(int j = 0; j < 16; j++) {
            int y = x + j;
            int cnt = 0;
            while(y % 2 == 0) {
                cnt++;
                y /= 2;
            }

            res = min(res, j + 15 - cnt);
        }

        cout << res << ' ';

//        cout << calc(x) << ' ';
    }
//    cout << endl;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int t = 1;
//    cin >> t;

    while(t--)
        solve();
}