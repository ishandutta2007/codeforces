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
const int N = 1e5 + 13;
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

int a[N][2];
string s[N][2];
li dp[N][2];

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n;
    cin >> n;

    for(int i = 0; i < n; i++) {
        cin >> a[i][1];
        a[i][0] = 0;
    }

    for(int i = 0; i < n; i++) {
        cin >> s[i][0];
        s[i][1] = s[i][0];
        reverse(s[i][1].begin(), s[i][1].end());
    }

    dp[0][0] = 0;
    dp[0][1] = a[0][1];

    for(int i = 1; i < n; i++) {
        for(int j = 0; j < 2; j++) {
            dp[i][j] = INF64;
            for(int k = 0; k < 2; k++) {
                if(s[i][j] >= s[i - 1][k])
                    dp[i][j] = min(dp[i][j], dp[i - 1][k] + a[i][j]);
            }
        }
    }

    li ans = min(dp[n - 1][0], dp[n - 1][1]);

    cout << (ans < INF64 ? ans : -1ll) << endl;
}