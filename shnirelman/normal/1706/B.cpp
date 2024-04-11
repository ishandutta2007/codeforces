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
//int dp[N];
//int res[N];
vector<int> pos[N];

void solve() {
    int n;
    cin >> n;

    for(int i = 0; i < n; i++) {
//        res[i] = dp[i] = 0;
        pos[i].erase(pos[i].begin(), pos[i].end());
    }

    for(int i = 0; i < n; i++) {
        cin >> a[i];
        a[i]--;

        pos[a[i]].push_back(i);
    }

//    for(int i = 0; i < n; i++) {
//        dp[i] = 1;
//        if(i > 0 && a[i - 1] == a[i])
//            dp[i] = max(dp[i], dp[i - 1] + 1);
//        if(i > 2 && a[i - 3] == a[i])
//            dp[i] = max(dp[i], dp[i - 3] + 1);
//
//        res[a[i]] = max(res[a[i]], dp[i]);
//    }
//
//    for(int i = 0; i < n; i++)
//        cout << res[i] << ' ';
//    cout << endl;

    for(int i = 0; i < n; i++) {
        vector<int> dp(2, 0);
        for(int j : pos[i]) {
            int x = (j & 1);
            int y = (x ^ 1);
            dp[y] = max(dp[y], dp[x] + 1);
        }
//        for(int x : pos[i])
//            cnt[x % 2]++;
        cout << max(dp[0], dp[1]) << ' ';
    }
    cout << endl;
}

signed main() {
//    ios::sync_with_stdio(0);
//    cin.tie(0);

    int t = 1;
    cin >> t;

    while(t--)
        solve();
}