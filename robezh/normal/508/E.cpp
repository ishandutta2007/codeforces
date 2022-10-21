#include <bits/stdc++.h>
using namespace std;

const int N = (int)1205;

struct P {
    int l, r;
};

int n;
int dp[N][N];
int st[N][N];
int lb[N], rb[N];
char res[N];

int solve(int l, int r) {
    if(l > r) return 1;
    if(dp[l][r] != -1) return dp[l][r];
    for(int md = lb[l] / 2; md <= min((rb[l] - 1) / 2, r - l); md++) {
        int res = 1;
        if(md != 0) res &= solve(l + 1, l + md);
        if(l + md + 1 <= r) res &= solve(l + md + 1, r);
        if(res == 1) {
            st[l][r] = md;
            return dp[l][r] = 1;
        }
    }
    return dp[l][r] = 0;
}

void fill_ans(int l, int r, int off) {
    res[off] = '(';
    int md = st[l][r];
    res[off + 2 * md + 1] = ')';
    if(md != 0) fill_ans(l + 1, l + md, off + 1);
    if(l + md + 1 <= r) fill_ans(l + md + 1, r, off + 2 + 2 * md);
}

int main() {
    cin >> n;
    for(int i = 0; i < n; i++) cin >> lb[i] >> rb[i];
    memset(dp, -1, sizeof(dp));
    if(solve(0, n - 1)) {
        fill_ans(0, n - 1, 0);
        for(int i = 0; i < 2 * n; i++) cout << res[i];
        cout << endl;
    }
    else cout << "IMPOSSIBLE" << endl;
}