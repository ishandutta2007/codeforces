/**
 * Author:
 * Date:
 * License:
 * Source:
 * Description: Require montonocity of $Opt(i)$. Solve one layer in $O(n \log n)$
 */
#include <bits/stdc++.h>
using namespace std;
const int N = (int)1e5 + 50;
typedef long long ll;
const ll INF = (ll)1e18;

int n,k;
int num[N];
int ql = 0, qr = -1;
ll dp[N], new_dp[N];
int freq[N];
ll C2[N];
ll tot_cost = 0;

void add(int x, int val) {
    tot_cost -= C2[freq[x]];
    freq[x] += val;
    tot_cost += C2[freq[x]];
}

void slide(int nl, int nr) {
    while(ql < nl) {
        add(num[ql], -1);
        ql ++;
    }
    while(ql > nl) {
        ql --;
        add(num[ql], 1);
    }
    while(qr < nr) {
        qr++;
        add(num[qr], 1);
    }
    while(qr > nr) {
        add(num[qr], -1);
        qr --;
    }
}

void solve(int L, int R, int hl, int hr) {
    if(L > R) return ;
    int M = (L + R) / 2;
    int h = -1; new_dp[M] = INF;
    for(int i = hl; i <= min(M, hr); i++) {
        slide(i, M);
        if(dp[i-1] + tot_cost < new_dp[M]) {
            new_dp[M] = dp[i-1] + tot_cost;
            h = i;
        }
    }
    solve(L, M-1, hl, h);
    solve(M+1, R, h, hr);
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    for(int i = 0; i < N; i++) C2[i] = 1LL * i * (i - 1) / 2;
    cin >> n >> k;

    for(int i = 1; i <= n; i++) cin >> num[i];
    dp[0] = 0;
    for(int i = 1; i <= n; i++) dp[i] = INF;
    for(int i = 1; i <= k; i++) {
        solve(1, n, 1, n);
        for(int j = 1; j <= n; j++) dp[j] = new_dp[j];
    }
    cout << dp[n] << endl;
}