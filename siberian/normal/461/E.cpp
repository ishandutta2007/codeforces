#include <bits/stdc++.h>

using namespace std;

using ll = long long;
using ull = unsigned long long;
using ld = long double;

#define all(a) (a).begin(), (a).end()

// mt19937 rnd(chrono::steady_clock::now().time_since_epoch().count());

template<typename T1, typename T2> 
inline void chkmin(T1& x, const T2& y) {
    if (y < x) x = y;
}

template<typename T1, typename T2>
inline void chkmax(T1& x, const T2& y) {
    if (x < y) x = y;
}

#define int ll

ll len;
string t;
int n;

const int N = 1e5 + 10;
const int A = 4;
const int BUBEN_LEN = 10;

int minWord[A][A];

vector<string> have[BUBEN_LEN];

void relax(const string& s) {
    if (s.size() < 2) return;
    // have[s.size() - 1].push_back(s);
    if (binary_search(all(have[s.size() - 1]), s)) return;
    // cerr << "s = " << s << endl;
    if (!binary_search(all(have[s.size() - 2]), s.substr(0, s.size() - 1))) return;
    chkmin(minWord[s[0] - 'A'][s.back() - 'A'], s.size());
}

void rec(string& s) {
    relax(s);
    if (s.size() == BUBEN_LEN) return;
    s += 'A';
    for (int i = 0; i < A; ++i) {
        rec(s);
        s[s.size() - 1]++;
    }
    s.pop_back();
}

int dp[N][A][A];
int fans[N][A];

void precalc() {
    for (int i = 0; i < A; ++i) {
        for (int j = 0; j < A; ++j) {
            minWord[i][j] = N;
        }
    }
    for (int i = 0; i < n; ++i) {
        string now = "";
        for (int j = 0; i + j < n && j < BUBEN_LEN; ++j) {
            now += t[i + j];
            have[j].push_back(now);
        }
    }
    for (int i = 0; i < BUBEN_LEN; ++i) {
        sort(all(have[i]));
        have[i].resize(unique(all(have[i])) - have[i].begin());
    }
    string s;
    rec(s);
    // for (int i = 0; i < A; ++i) {
    //     for (int j = 0; j < A; ++j) {
    //         assert(minWord[i][j] != N);
    //         cerr << minWord[i][j] << " ";
    //     }
    //     cerr << endl;
    // }
    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < A; ++j) {
            for (int k = 0; k < A; ++k) {
                dp[i][j][k] = -1;
            }
        }
    }

    // cerr << "minWord = " << endl;
    // for (int i = 0; i < A; ++i) {
    //     for (int j = 0; j < A; ++j) {
    //         cerr << minWord[i][j] << " ";
    //     }
    //     cerr << endl;
    // }
    for (int first = 0; first < A; ++first) {
        for (int last = 0; last < A; ++last) {
            dp[minWord[first][last] - 1][first][last] = 1;
            // dp[0][first][last] = 0;
        }
    }
    // cerr << "dp[1][D][A] = " << dp[1]['D' - 'A']['A' - 'A'] << endl;
    for (int len = 0; len < N; ++len) {
        for (int begin = 0; begin < A; ++begin) {
            for (int first = 0; first < A; ++first) {
                if (dp[len][begin][first] == -1) continue;
                // if (len + 1 < N) {
                //     chkmax(dp[len + 1][begin][first], dp[len][begin][first]);
                // }
                for (int last = 0; last < A; ++last) {
                    int nxtLen = len + minWord[first][last] - 1;
                    if (nxtLen >= N) continue;
                    chkmax(dp[nxtLen][begin][last], dp[len][begin][first] + 1);
                }
            }
        }
    }
    for (int i = 0; i < A; ++i) {
        for (int j = 0; j < A; ++j) {
            dp[0][i][j] = 0;
        }
    }
    // cerr << "dp[3][D][D] = " << dp[3]['D' - 'A']['D' - 'A'] << endl;
    // cerr << "dp[4][D][A] = " << dp[4]['D' - 'A']['A' - 'A'] << endl;
    // cerr << "dp[5][D][A] = " << dp[5]['D' - 'A']['A' - 'A'] << endl;
    for (int len = 0; len < N; ++len) {
        for (int begin = 0; begin < A; ++begin) {
            for (int end = 0; end < A; ++end) {
                chkmax(fans[len][begin], dp[len][begin][end]);
                for (int last = 0; last < A; ++last) {
                    int nxtLen = len + minWord[end][last] - 1;
                    if (nxtLen >= N) continue;
                    for (int j = len + 1; j <= nxtLen; ++j) {
                        chkmax(fans[j][begin], dp[len][begin][end] + 1);
                    }
                }
            }
        }
    }

    // cerr << "fans = " << endl;
    // for (int i = 0; i < A; ++i) {
    //     cerr << char(i + 'A') << endl;
    //     for (int j = 0; j < N; ++j) {
    //         cerr << fans[j][i] << " ";
    //     }
    //     cerr << endl;
    // }

    // cerr << "dp = " << endl;
    // for (int i = 0; i < A; ++i) {
    //     cerr << char(i + 'A') << endl;
    //     for (int j = 0; j < N; ++j) {
    //         cerr << dp[j][i][i] << " ";
    //     }
    //     cerr << endl;
    // }

    
}

signed main() {
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    cout.precision(20), cout.setf(ios::fixed);
    cin >> len >> t;
    n = t.size();
    precalc();
    if (len < N) {
        int ans = 0;
        for (int i = 0; i < A; ++i) {
            chkmax(ans, fans[len][i]);
        }
        cout << ans << endl;
    } else {
        ll ans = 0;
        for (int cycleLen = 1; cycleLen < N; ++cycleLen) {
            for (int begin = 0; begin < A; ++begin) {
                ll cnt = len / cycleLen;
                int pref = len % cycleLen;
                ll myFans = dp[cycleLen][begin][begin] * cnt;
                for (int other = 0; other < A; ++other){
                    int frelax = myFans + fans[pref][begin];
                    // if (frelax == 47) {
                    //     cerr << "cycleLen = " << cycleLen << " begin = " << begin << " other = " << other << " myFans = " << myFans << endl;
                    // }
                    chkmax(ans, frelax);
                    frelax = myFans + dp[pref][other][begin];
                    chkmax(ans, frelax);
                }
            }
        }
        cout << ans << endl;
    }
    return 0;
}