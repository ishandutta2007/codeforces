#include <bits/stdc++.h>

using namespace std;

using ll = long long;
using ull = unsigned long long;
using ld = long double;

#define pbc push_back
#define pob pop_back()
#define mp make_pair
#define all(a) (a).begin(), (a).end()
#define vin(a) for (auto& i : a) cin >> i

// mt19937 rnd(chrono::steady_clock::now().time_since_epoch().count());

template<typename T1, typename T2> 
inline void chkmin(T1& x, const T2& y) {
    if (y < x) x = y;
}

template<typename T1, typename T2>
inline void chkmax(T1& x, const T2& y) {
    if (x < y) x = y;
}

const int N = 11;
const int A = 2 * ('Z' - 'A' + 1 + 'z' - 'a' + 1);

struct fdp{
    int ans = -1;
    int pos = -1;
    int mask = 0;
    fdp() : ans(-1), pos(-1), mask(0) {}
    fdp(int ans_, int pos_, int mask_) : ans(ans_), pos(pos_), mask(mask_) {}
    bool operator<(const fdp& other) const {
        return ans < other.ans;
    }
};

int n;
string s[N];
vector<int> has[N][A];
bool ok[A][1 << N];
fdp dp[A][1 << N];
int lenAns;
string ans;

void clear() {
    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < A; ++j) {
            has[i][j].clear();
        }
    }
    for (int i = 0; i < A; ++i) {
        for (int j = 0; j < (1 << N); ++j) {
            ok[i][j] = false;
            dp[i][j] = fdp();
        }
    }
    lenAns = 0;
    ans = "";
}

int getId(char x) {
    if ('a' <= x && x <= 'z') {
        return x - 'a';
    } else if ('A' <= x && x <= 'Z') {
        return x - 'A' + 26;
    } else {
        throw;
    }
}

char getLett(int x) {
    if (x < 26) {
        return x + 'a';
    }
    return x - 26 + 'A';
}

void build() {
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < s[i].size(); ++j) {
            has[i][getId(s[i][j])].push_back(j);
        }
    }
    // cerr << "has = " << endl;
    // for (int i = 0; i < n; ++i) {
    //     cerr << "i = " << i << endl;
    //     for (int j = 0; j < A; ++j) {
    //         if (has[i][j].empty()) continue;
    //         cerr << "let = " << getLett(j) << " : ";
    //         for (auto cur : has[i][j]) {
    //             cerr << cur << " ";
    //         }
    //         cerr << endl;
    //     }
    // }
    for (int pos = 0; pos < s[0].size(); ++pos) {
        for (int mask = 0; mask < (1 << n); ++mask) {
            bool flag = true;
            for (int bit = 0; bit < n; ++bit) {
                flag &= (((mask >> bit) & 1) + 1) <= has[bit][getId(s[0][pos])].size();
            }
            ok[pos][mask] = flag;
        }
    }
    // cerr << "ok = " << endl;
    // for (int i = 0; i < s[0].size(); ++i) {
    //     cerr << ok[i][0] << " ";
    // }
    // cerr << endl;
}

void relax(int pos) {
    if (ok[pos][0]) {
        chkmax(dp[pos][0], fdp(1, -1, 0));
        for (int mask = 0; mask < (1 << n); ++mask) {
            for (int bit = 0; bit < n; ++bit) {
                if ((mask >> bit) & 1) {
                    chkmax(dp[pos][mask], fdp(dp[pos][mask ^ (1 << bit)].ans, pos, mask ^ (1 << bit)));
                }
            }
        }
    }
}

int getNextMask(int pos, int mask, int nextPos) {
    if (!ok[pos][mask]) {
        return -1;
    }
    if (s[0][pos] == s[0][nextPos]) {
        if (mask != 0) {
            return -1;
        }
        for (int bit = 0; bit < n; ++bit) {
            if (has[bit][getId(s[0][pos])].size() != 2) {
                return -1;
            }
        }
        return (1 << n) - 1;
    } else {
        int nextMask = 0;
        for (int bit = 0; bit < n; ++bit) {
            auto& myPrev = has[bit][getId(s[0][pos])];
            // cerr << "bit = " << bit << endl;
            int prev = myPrev[(mask >> bit) & 1];
            // cerr << "bit = " << bit << " prev = " << prev << endl;
            auto& myHas = has[bit][getId(s[0][nextPos])];
            int cur = 0;
            while (cur < myHas.size() && myHas[cur] < prev) ++cur;
            if (cur == myHas.size()) {
                return -1;
            }
            nextMask |= (1 << bit) * cur;
        }
        return nextMask;
    }
}

void calcDp() {
    for (int pos = 0; pos < s[0].size(); ++pos) {
        // cerr << "pos = " << pos << endl;
        relax(pos);
        // cerr << "relax: ok" << endl;
        for (int mask = 0; mask < (1 << n); ++mask) {
            if (dp[pos][mask].ans == -1) {
                continue;
            }
            for (int nextPos = pos + 1; nextPos < s[0].size(); ++nextPos) {
                // cerr << "mask = " << mask << " nextPos = " << nextPos << endl;
                int nextMask = getNextMask(pos, mask, nextPos);
                // cerr << "ok" << endl;
                if (nextPos == -1) {
                    continue;
                }
                chkmax(dp[nextPos][nextMask], fdp(dp[pos][mask].ans + 1, pos, mask));
            }
        }
    }    
}

void restoreAns() {
    // for (int i = 0; i < s[0].size(); ++i) {
    //     for (int mask = 0; mask < (1 << n); ++mask) {
    //         cout << "i = " << i << " mask = " << mask << " ans = " << dp[i][mask].ans << " posPrev = " << dp[i][mask].pos << " maskPrev = " << dp[i][mask].mask << endl;
    //     }
    // }
    fdp fans;
    for (int i = 0; i < s[0].size(); ++i) {
        for (int mask = 0; mask < (1 << n); ++mask) {
            chkmax(fans, fdp(dp[i][mask].ans, i, mask));
        }
    }
    lenAns = fans.ans;
    if (lenAns == -1) {
        lenAns = 0;
        return;
    }
    ans = "";
    int curPos = fans.pos;
    int curMask = fans.mask;
    // cerr << "fans.pos = " << fans.pos << " fans.mask = " << fans.mask << endl; 
    for (int i = 0; i < fans.ans; ++i) {
        assert(curPos != -1);
        if (dp[curPos][curMask].pos != curPos) {
            ans += s[0][curPos];
        }
        // cerr << "curPos = " << curPos << " curMask = " << curMask << endl;
        int nextPos = dp[curPos][curMask].pos;
        int nextMask = dp[curPos][curMask].mask;
        curPos = nextPos;
        curMask = nextMask;
    }
    reverse(all(ans));
}

void check(int id) {
    int cur = 0;
    if (cur == ans.size()) return;
    for (auto x : s[id]) {
        if (x == ans[cur]) ++cur;
        if (cur == ans.size()) return;
    }
    assert(cur == ans.size());
}

void check() {
    for (int i = 0; i < n; ++i) {
        check(i);
    }
}

void solve() {
    cin >> n;
    for (int i = 0; i < n; ++i) {
        cin >> s[i];
    }
    build();
    // cerr << "build: ok" << endl;
    calcDp();
    // cerr << "calcDp: ok" << endl;
    restoreAns();
    // cerr << "restoreAns: ok" << endl;
    cout << lenAns << '\n';
    cout << ans << '\n';
    cout.flush();
    check();
}

signed main() {
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    cout.precision(20), cout.setf(ios::fixed);
    int t;
    cin >> t;
    while (t--) {
        clear();
        solve();
    }
    return 0;
}