#ifdef LOCAL
#define _GLIBCXX_DEBUG
#endif
#include <bits/stdc++.h>
using namespace std;

string digs[] = {"1110111", "0010010", "1011101", "1011011", "0111010", "1101011", "1101111", "1010010", "1111111", "1111011"};
string inp[2100];
int dp[2100][2100];
int diffs[2100][10];
int n,k;

int can(int pos, int rem) {
    if (pos == n) return rem == 0;
    if (rem < 0) return 0;

    int &ret = dp[pos][rem];
    if (ret == -1) {
        ret = 0;

        for (int d = 0; d <= 9; d++) {
            int diff = diffs[pos][d];
            if (diff <= rem && diff != -1) {
                ret |= can(pos+1, rem - diff);
            }
        }
    }

    return ret;
}

int get_diff(const string& src, const string &dst) {
    int r = 0;
    for (int i = 0; i < 7; i++) {
        if (dst[i] == '0' && src[i] == '1') return -1;
        if (dst[i] == '1' && src[i] == '0') r++;
    }
    return r;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    memset(dp,-1,sizeof(dp));

    cin >> n >> k;
    for (int i = 0; i < n; i++) {
        cin >> inp[i];
    }

    for (int i = 0; i < n; i++) {
        for (int d = 0; d <= 9; d++) {
            diffs[i][d] = get_diff(inp[i], digs[d]);
        }
    }

    bool good = false;
    for (int i = 0; i < n; i++) {
        for (int d = 9; d >= 0; d--) {
            int diff = diffs[i][d];
            if (diff <= k && diff != -1 && can(i+1, k-diff)) {
                good = true;
                k -= diff;
                cout << d;
                break;
            }
        }

        if (!good) break;
    }

    if (!good) cout << -1;
    cout << endl;

    return 0;
}