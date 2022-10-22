#include <bits/stdc++.h>

#define f first
#define s second

using namespace std;
using li = long long;
using ld = long double;
using pii = pair<int, int>;

const int INF = 2e9 + 13;
const int M = 998244353;
const int g = 3;
const int ALF = (1 << 20) - 3;
const int N = 3e5 + 13;
//const int N = 20 + 13;
const int K = 2e5 + 13;
//const int K = 20 + 13;
const int LOGN = 23;
const ld PI = acos(-1);
const ld eps = 1e-4;
const int S = 1007;
const int A = 203;

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

int a[N];
int dp[N];

void solve() {
    int n;
    cin >> n;

    for(int i = 0; i < n; i++) {
//        for(int j = 0; j < A; j++)
//            dp[i][j] = 0;
            dp[i] = 0;
    }

    for(int i = 0; i < n; i++)
        cin >> a[i];

    int ans = 0;
    for(int i = 0; i < n; i++) {
        dp[i] = 1;
        for(int j = max(0, i - 300); j < i; j++) {
            if((a[j] ^ i) < (a[i] ^ j))
                dp[i] = max(dp[i], dp[j] + 1);
        }

        ans = max(ans, dp[i]);
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