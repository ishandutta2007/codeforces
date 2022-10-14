#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <cmath>
#include <vector>
#include <set>
#include <map>
#include <unordered_set>
#include <unordered_map>
#include <queue>
#include <ctime>
#include <cassert>
#include <complex>
#include <string>
#include <cstring>
#include <chrono>
#include <random>
#include <queue>
#include <bitset>

#define pb push_back
#define int long long
#define str string
using namespace std;
const int M = 1000000007;
int R[505][505], B[505][505], G[505][505], Y[505][505];
int ST[525][525][13][13];
vector<int> pows = {1};
vector<int> logi = {0, 0};

int rsum(int r1, int c1, int r2, int c2) {
    int ans = 0;
    ans += R[r2][c2];
    ans -= R[r2][c1 - 1];
    ans -= R[r1 - 1][c2];
    ans += R[r1 - 1][c1 - 1];
    return ans;
}

int gsum(int r1, int c1, int r2, int c2) {
    int ans = 0;
    ans += G[r2][c2];
    ans -= G[r2][c1 - 1];
    ans -= G[r1 - 1][c2];
    ans += G[r1 - 1][c1 - 1];
    return ans;
}

int bsum(int r1, int c1, int r2, int c2) {
    int ans = 0;
    ans += B[r2][c2];
    ans -= B[r2][c1 - 1];
    ans -= B[r1 - 1][c2];
    ans += B[r1 - 1][c1 - 1];
    return ans;
}

int ysum(int r1, int c1, int r2, int c2) {
    int ans = 0;
    ans += Y[r2][c2];
    ans -= Y[r2][c1 - 1];
    ans -= Y[r1 - 1][c2];
    ans += Y[r1 - 1][c1 - 1];
    return ans;
}

struct sparse2d {
    int n, m, logn, logm;

    sparse2d(vector<vector<int>> A) {
        n = (int) A.size();
        m = (int) A[0].size();
        logn = (int) ceil(log2(n + 1));
        logm = (int) ceil(log2(m + 1));
        for (int i = 0; i < 30; i++) pows.pb(2 * pows.back());
        for (int i = 2; i < 507; i++) logi.pb(logi[i / 2] + 1);
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                ST[i][j][0][0] = A[i][j];
            }
        }
        for (int i = 0; i < n; i++) {
            for (int lg = 1; lg < logm; lg++) {
                for (int j = 0; j < m; j++) {
                    ST[i][j][0][lg] = max(ST[i][j][0][lg - 1], ST[i][j + pows[lg - 1]][0][lg - 1]);
                }
            }
        }
        for (int k1 = 1; k1 < logn; k1++) {
            for (int i = 0; i < n; i++) {
                for (int j = 0; j < m; j++) {
                    for (int k2 = 0; k2 < logm; k2++) {
                        ST[i][j][k1][k2] = ST[i][j][k1 - 1][k2];
                        if (i + pows[k1 - 1] < 510) {
                            ST[i][j][k1][k2] = max(ST[i][j][k1][k2], ST[i + pows[k1 - 1]][j][k1 - 1][k2]);
                        }
                    }
                }
            }
        }
    }

    int answer(int x1, int y1, int x2, int y2) {
        int k1 = logi[x2 - x1 + 1];
        int k2 = logi[y2 - y1 + 1];
        int a1 = ST[x1][y1][k1][k2];
        int a2 = ST[x2 - pows[k1] + 1][y1][k1][k2];
        int a3 = ST[x1][y2 - pows[k2] + 1][k1][k2];
        int a4 = ST[x2 - pows[k1] + 1][y2 - pows[k2] + 1][k1][k2];
        return max(max(max(a1, a2), a3), a4);
    }
};

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int n, m, q;
    cin >> n >> m >> q;
    vector<str> nano(n + 1);
    for (int i = 1; i <= n; i++) {
        cin >> nano[i];
        nano[i] = " " + nano[i];
    }
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            R[i][j] = R[i - 1][j] + R[i][j - 1] - R[i - 1][j - 1];
            G[i][j] = G[i - 1][j] + G[i][j - 1] - G[i - 1][j - 1];
            B[i][j] = B[i - 1][j] + B[i][j - 1] - B[i - 1][j - 1];
            Y[i][j] = Y[i - 1][j] + Y[i][j - 1] - Y[i - 1][j - 1];
            if (nano[i][j] == 'R') {
                R[i][j]++;
            } else if (nano[i][j] == 'G') {
                G[i][j]++;
            } else if (nano[i][j] == 'B') {
                B[i][j]++;
            } else {
                Y[i][j]++;
            }
        }
    }
    vector<int> flr(m + 2);
    vector<vector<int>> uz(n + 2, flr);
    for (int i = 2; i <= n; i++) {
        for (int j = 2; j <= m; j++) {
            int left = 0;
            int right = 1 + min(min(min(i - 1, j - 1), n - i + 1), m - j + 1);
            while (right - left > 1) {
                int mid = (left + right) / 2;
                int r1 = rsum(i - mid, j - mid, i - 1, j - 1);
                int b1 = bsum(i, j, i + mid - 1, j + mid - 1);
                int g1 = gsum(i - mid, j, i, j + mid - 1);
                int y1 = ysum(i, j - mid, i + mid - 1, j);
                if (mid * mid == r1 && mid * mid == b1 && mid * mid == g1 && mid * mid == y1) {
                    left = mid;
                } else {
                    right = mid;
                }
            }
            uz[i][j] = left;
        }
    }
    sparse2d SP = *(new sparse2d(uz));
    while (q--) {
        int r1, c1, r2, c2;
        cin >> r1 >> c1 >> r2 >> c2;
        int left = 0;
        int right = 10000;
        while (right - left > 1) {
            int k = (left + right) / 2;
            int x1 = r1 + k, x2 = r2 - k + 1, y1 = c1 + k, y2 = c2 - k + 1;
            if (x1 > x2 || y1 > y2) {
                right = k;
            } else {
                int ans = SP.answer(x1, y1, x2, y2);
                if (ans >= k) {
                    left = k;
                } else {
                    right = k;
                }

            }
        }
        cout << 4 * left * left << '\n';
    }
}