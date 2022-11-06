#include<bits/stdc++.h>
using namespace std;

int n, m;
char A[1010101][3];
int here[1010101];

#define bit(mask, i) ((mask >> i) & 1)

bool check(int mask1, int mask2) {
    for (int i = 0; i + 1 < m; ++i) {
        int sum = bit(mask1, i) ^ bit(mask2, i) ^ bit(mask1, i + 1) ^ bit(mask2, i + 1);
        if (sum == 0)
            return 0;
    }
    return 1;
}

int cost(int i, int mask) {
    int res = 0;
    mask ^= here[i];
    while (mask > 0) {
        ++res;
        mask &= mask - 1;
    }
    return res;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> n >> m;
    if (n >= 4 && m >= 4) {
        cout << -1;
        return 0;
    }
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            if (n > m)
                cin >> A[i][j];
            else
                cin >> A[j][i];
        }
    }
    if (n <= m)
        swap(n, m);
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j)
            here[i] |= (1 << j) * (A[i][j] - '0');
    }
    int P = 1 << m;
    vector<int> dp(P);
    for (int mask = 0; mask < P; ++mask)
        dp[mask] = cost(0, mask);
    for (int i = 1; i < n; ++i) {
        vector<int> ndp(P, 1e9);
        for (int mask = 0; mask < P; ++mask) {
            int need = cost(i, mask);
            for (int pr = 0; pr < P; ++pr)
                if (check(pr, mask))
                    ndp[mask] = min(ndp[mask], dp[pr] + need);
        }
        dp = ndp;
    }
    cout << *min_element(dp.begin(), dp.end());
    return 0;
}