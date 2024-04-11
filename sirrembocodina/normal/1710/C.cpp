#pragma GCC target ("avx2")
#pragma GCC optimization ("O3")
#pragma GCC optimization ("unroll-loops")
#include <ext/pb_ds/assoc_container.hpp>
using namespace __gnu_pbds;
#include <bits/stdc++.h>

using namespace std;

#define int int64_t
#define forn(i, n) for (int i = 0; i < (int)(n); i++)

struct my_hash {
    inline size_t operator()(const pair<int, int>& a) const {
        return a.first * 31 + a.second;
    }
};

int mod = 998244353;

void add(int& a, int b) {
    a += b;
    if (a >= mod) {
        a -= mod;
    }
}

int32_t main() {
    srand(time(nullptr));
    ios_base::sync_with_stdio(0);
    int t = 1;
    //cin >> t;
    while (t--) {
        string s;
        cin >> s;
        int n = s.size();
        int dp[2][2][2][2][2][2]; // a, b, c, ab, bc, ac
        for (int a = 0; a < 2; a++) {
            for (int b = 0; b < 2; b++) {
                for (int c = 0; c < 2; c++) {
                    for (int ab = 0; ab < 2; ab++) {
                        for (int bc = 0; bc < 2; bc++) {
                            for (int ac = 0; ac < 2; ac++) {
                                dp[a][b][c][ab][bc][ac] = 0;
                            }
                        }
                    }
                }
            }
        }
        dp[0][0][0][0][0][0] = 1;
        for (char ccc: s) {
            bool cc = ccc == '1';
            int new_dp[2][2][2][2][2][2]; // a, b, c, ab, bc, ac
            for (int a = 0; a < 2; a++) {
                for (int b = 0; b < 2; b++) {
                    for (int c = 0; c < 2; c++) {
                        for (int ab = 0; ab < 2; ab++) {
                            for (int bc = 0; bc < 2; bc++) {
                                for (int ac = 0; ac < 2; ac++) {
                                    new_dp[a][b][c][ab][bc][ac] = 0;
                                }
                            }
                        }
                    }
                }
            }
            for (int a = 0; a < 2; a++) {
                for (int b = 0; b < 2; b++) {
                    for (int c = 0; c < 2; c++) {
                        for (int ab = 0; ab < 2; ab++) {
                            for (int bc = 0; bc < 2; bc++) {
                                for (int ac = 0; ac < 2; ac++) {
                                    // 000
                                    add(new_dp[a || cc][b || cc][c || cc][ab][bc][ac], dp[a][b][c][ab][bc][ac]);
                                    // 001
                                    if (c || cc) {
                                        add(new_dp[a || cc][b || cc][c][1][bc][ac], dp[a][b][c][ab][bc][ac]);
                                    }
                                    // 010
                                    if (b || cc) {
                                        add(new_dp[a || cc][b][c || cc][ab][bc][1], dp[a][b][c][ab][bc][ac]);
                                    }
                                    // 011
                                    if ((b & c) || cc) {
                                        add(new_dp[a || cc][b][c][ab][1][ac], dp[a][b][c][ab][bc][ac]);
                                    }
                                    // 100
                                    if (a || cc) {
                                        add(new_dp[a][b || cc][c || cc][ab][1][ac], dp[a][b][c][ab][bc][ac]);
                                    }
                                    // 101
                                    if ((a & c) || cc) {
                                        add(new_dp[a][b || cc][c][ab][bc][1], dp[a][b][c][ab][bc][ac]);
                                    }
                                    // 110
                                    if ((a & b) || cc) {
                                        add(new_dp[a][b][c || cc][1][bc][ac], dp[a][b][c][ab][bc][ac]);
                                    }
                                    // 111
                                    if ((a & b & c) || cc) {
                                        add(new_dp[a][b][c][ab][bc][ac], dp[a][b][c][ab][bc][ac]);
                                    }
                                }
                            }
                        }
                    }
                }
            }
            for (int a = 0; a < 2; a++) {
                for (int b = 0; b < 2; b++) {
                    for (int c = 0; c < 2; c++) {
                        for (int ab = 0; ab < 2; ab++) {
                            for (int bc = 0; bc < 2; bc++) {
                                for (int ac = 0; ac < 2; ac++) {
                                    dp[a][b][c][ab][bc][ac] = new_dp[a][b][c][ab][bc][ac];
                                }
                            }
                        }
                    }
                }
            }
        }
        int ans = 0;
        for (int a = 0; a < 2; a++) {
            for (int b = 0; b < 2; b++) {
                for (int c = 0; c < 2; c++) {
                    add(ans, dp[a][b][c][1][1][1]);
                }
            }
        }
        cout << ans;
    }
}