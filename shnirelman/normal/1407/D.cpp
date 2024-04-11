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
const int N = 3e5 + 13;
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

int a[N];
int dp[N];

int rg_gr[N], rg_lw[N];

void solve() {
    int n;
    cin >> n;

    for(int i = 0; i < n; i++) {
        cin >> a[i];
    }


    dp[0] = 0;
    stack<int> st_gr, st_lw;
    st_gr.push(0);
    st_lw.push(0);

    for(int i = 1; i < n; i++) {
        dp[i] = dp[i - 1] + 1;
        while(!st_gr.empty()) {
            int j = st_gr.top();
            dp[i] = min(dp[i], dp[j] + 1);
            if(a[j] >= a[i]) {
                st_gr.pop();
            }
            if(a[j] <= a[i]) {
                break;
            }
        }

        st_gr.push(i);

        while(!st_lw.empty()) {
            int j = st_lw.top();
            dp[i] = min(dp[i], dp[j] + 1);
            if(a[j] <= a[i]) {
                st_lw.pop();
            }
            if(a[j] >= a[i]) {
                break;
            }
        }

        st_lw.push(i);
    }

    cout << dp[n - 1] << endl;
}

signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int t = 1;
//    cin >> t;

    while(t--)
        solve();
}