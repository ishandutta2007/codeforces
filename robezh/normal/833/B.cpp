#include <bits/stdc++.h>
using namespace std;

const int N = 35005, INF = (int)1e9;

int n,k;
int num[N];
int ql = 0, qr = -1;
int dp[N], new_dp[N];
int freq[N], cur_cnt = 0;

void slide(int nl, int nr) {
    while(ql < nl) {
        if(--freq[num[ql]] == 0) cur_cnt --;
        ql ++;
    }
    while(ql > nl) {
        ql --;
        if(freq[num[ql]]++ == 0) cur_cnt ++;
    }
    while(qr < nr) {
        qr++;
        if(freq[num[qr]]++ == 0) cur_cnt ++;
    }
    while(qr > nr) {
        if(--freq[num[qr]] == 0) cur_cnt --;
        qr --;
    }
}

void solve(int L, int R, int hl, int hr) {
    if(L > R) return ;
    int M = (L + R) / 2;
    int h = -1; new_dp[M] = -INF;
    for(int i = hl; i <= min(M, hr); i++) {
        slide(i, M);
        if(dp[i-1] + cur_cnt > new_dp[M]) {
            new_dp[M] = dp[i-1] + cur_cnt;
            h = i;
        }
    }
    solve(L, M-1, hl, h);
    solve(M+1, R, h, hr);
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n >> k;

    for(int i = 1; i <= n; i++) cin >> num[i];
    dp[0] = 0;
    for(int i = 1; i <= n; i++) dp[i] = -INF;
    for(int i = 1; i <= k; i++) {
        solve(1, n, 1, n);
        for(int j = 1; j <= n; j++) dp[j] = new_dp[j];
    }
    cout << dp[n] << endl;
}