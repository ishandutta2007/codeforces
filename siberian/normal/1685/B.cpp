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

int getChar(char x) {
    if (x == 'A') {
        return 0;
    } else if (x == 'B') {
        return 1;
    } else {
        throw;
    }
}

void solve() {
    int a, b, cntAB, cntBA;
    cin >> a >> b >> cntAB >> cntBA;
    string s;
    cin >> s;
    int cntA = 0, cntB = 0;
    for (auto i : s) {
        cntA += i == 'A';
        cntB += i == 'B';
    }
    if (cntA != a + cntAB + cntBA || cntB != b + cntAB + cntBA) {
        cout << "NO\n";
        return;
    }
    vector<int> cnt[2][2];
    for (int i = 0; i < 2; ++i) {
        for (int j = 0; j < 2; ++j) {
            cnt[i][j] = {};
        }
    }
    for (int l = 0; l < (int)s.size(); ++l) {
        int r = l + 1;
        while (r < (int)s.size() && s[r] != s[r - 1]) {
            ++r;
        }
        if (r - l == 1) continue;
        int from = getChar(s[l]);
        int to = getChar(s[r - 1]);
        int len = r - l;
        cnt[from][to].push_back(len);
        l = r - 1;
    }
    for (int i = 0; i < 2; ++i) {
        for (int j = 0; j < 2; ++j) {
            // cerr << "i = " << i << " j = " << j << endl;
            // for (auto val : cnt[i][j]) {
            //     cerr << val << " ";
            // }
            // cerr << endl;
            sort(all(cnt[i][j]));
            reverse(all(cnt[i][j]));
        }
    }
    while ((!cnt[0][1].empty() || !cnt[1][0].empty()) && (cntAB > 0 || cntBA > 0)) {
        while (cntAB > 0 && !cnt[0][1].empty()) {
            int val = cnt[0][1].back() / 2;
            cnt[0][1].pop_back();
            int addVal = min(val, cntAB);
            val -= addVal;
            cntAB -= addVal;
            val *= 2;
            if (val > 0) {
                cnt[0][1].push_back(val);
            }
        }
        if (cntAB == 0) {
            while (!cnt[0][1].empty()) {
                int val = cnt[0][1].back();
                cnt[0][1].pop_back();
                if (val > 2) {
                    cnt[1][0].push_back(val - 2);
                }
            }
        }
        while (cntBA > 0 && !cnt[1][0].empty()) {
            int val = cnt[1][0].back() / 2;
            cnt[1][0].pop_back();
            int addVal = min(val, cntBA);
            val -= addVal;
            cntBA -= addVal;
            val *= 2;
            if (val > 0) {
                cnt[1][0].push_back(val);
            }
        }
        if (cntBA == 0) {
            while (!cnt[1][0].empty()) {
                int val = cnt[1][0].back();
                cnt[1][0].pop_back();
                if (val > 2) {
                    cnt[0][1].push_back(val - 2);
                }
            }   
        }
    }
    // cerr << "cntAB = " << cntAB << " cntBA = " << cntBA << endl;
    // for (int i = 0; i < 2; ++i) {
    //     for (int j = 0; j < 2; ++j) {
    //         cerr << "i = " << i << " j = " << j << endl;
    //         for (auto val : cnt[i][j]) {
    //             cerr << val << " ";
    //         }
    //         cerr << endl;
    //     }
    // }
    if (cntBA == 0 && cntAB == 0) {
        cout << "YES\n";
        return;
    }
    assert(cnt[0][1].empty() && cnt[0][1].empty());
    vector<int> has;
    for (auto i : cnt[0][0]) has.push_back(i);
    for (auto i : cnt[1][1]) has.push_back(i);

    while ((cntAB > 0 || cntBA > 0) && !has.empty()) {
        if (cntAB > 0) {
            int val = has.back();
            has.pop_back();
            if (val < 2) {
                continue;
            }
            cntAB--;
            val -= 2;
            if (val < 2) {
                continue;
            }
            has.push_back(val);
            continue;
        }
        if (cntBA > 0) {
            int val = has.back();
            has.pop_back();
            if (val < 2) {
                continue;
            }
            cntBA--;
            val -= 2;
            if (val < 2) {
                continue;
            }
            has.push_back(val);
            continue;    
        }
    }
    if (cntAB == 0 && cntBA == 0) {
        cout << "YES\n";
    } else {
        cout << "NO\n";
    }
}

signed main() {
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    cout.precision(20), cout.setf(ios::fixed);
    int t;
    cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}