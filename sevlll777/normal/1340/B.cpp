// #define _GLIBCXX_DEBUG

#include <iostream>
#include <iomanip>
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
#include <random>
#include <queue>
#include <bitset>

#define int long long
#define dbl long double
#define pb push_back
#define str string
using namespace std;
const int M = 998244353;


signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int n, k;
    cin >> n >> k;
    vector<string> S(n);
    for (int i = 0; i < n; i++) cin >> S[i];
    int mx = 0;
    for (auto s : S) {
        for (auto c : s) {
            mx += (c == '0');
        }
    }
    if (mx < k) {
        cout << -1;
        return 0;
    }
    vector<int> cnt = {6, 2, 5, 5, 4, 5, 6, 3, 7, 6};
    vector<string> B = {"1110111", "0010010", "1011101", "1011011", "0111010", "1101011", "1101111", "1010010", "1111111", "1111011"};
    int obj = 0;
    vector<int> M;
    for (auto s : S) {
        int mxm = 1e9;
        for (auto p : B) {
            int cc = 0;
            for (int i = 0; i < 7; i++) {
                if (p[i] == '0' && s[i] == '1') {
                    cc = 1e9;
                } else if (p[i] == '1' && s[i] == '0') {
                    cc += 1;
                }
            }
            mxm = min(mxm, cc);
        }
        obj += mxm;
        M.pb(mxm);
    }
    if (obj > k) {
        cout << -1;
        return 0;
    }
    for (int i = n - 2; i >= 0; i--) {
        M[i] += M[i + 1];
    }
    vector<int> C0(n);
    for (int i = 0; i < n; i++) {
        int cy = 0;
        for (auto c : S[i]) cy += (c == '0');
        C0[i] = cy;
    }
    for (int i = n - 2; i >= 0; i--) {
        C0[i] += C0[i + 1];
    }
    string ans = "";
    for (int i = 0; i < n - 1; i++) {
        for (int c = 9; c >= 0; c--) {
            bool can = true;
            int cnt_chng = 0;
            for (int j = 0; j < 7; j++) {
                if (S[i][j] == '1' && B[c][j] == '0') {
                    can = false;
                    break;
                } else if (S[i][j] == '0' && B[c][j] == '1') {
                    cnt_chng++;
                }
            }
            if (can) {
                if (M[i+1] <= k-cnt_chng && k-cnt_chng <= C0[i+1]) {
                    ans += (c + '0');
                    k -= cnt_chng;
                    break;
                }
            }
        }
    }
    for (int c = 9; c >= 0; c--) {
        int i = n - 1;
        bool can = true;
        int cnt_chng = 0;
        for (int j = 0; j < 7; j++) {
            if (S[i][j] == '1' && B[c][j] == '0') {
                can = false;
                break;
            } else if (S[i][j] == '0' && B[c][j] == '1') {
                cnt_chng++;
            }
        }
        if (can && k == cnt_chng) {
            ans += (c + '0');
            k -= cnt_chng;
            break;
        }
    }
    if (k) {
        pair<int, int> last = {-1, -1};
        for (int c = 9; c >= 0; c--) {
            int i = n - 1;
            bool can = true;
            int cnt_chng = 0;
            for (int j = 0; j < 7; j++) {
                if (S[i][j] == '1' && B[c][j] == '0') {
                    can = false;
                    break;
                } else if (S[i][j] == '0' && B[c][j] == '1') {
                    cnt_chng++;
                }
            }
            if (can && k > cnt_chng) {
                last = max(last, {cnt_chng, c});
            }
        }
        ans += (last.second + '0');
        k -= last.first;
        for (int i = n - 2; i >= 0; i--) {
            if (k == 0) break;
            pair<int, int> last = {-1, -1};
            for (int c = 9; c >= 0; c--) {
                bool can = true;
                int cnt_chng = 0;
                for (int j = 0; j < 7; j++) {
                    if (S[i][j] == '1' && B[c][j] == '0') {
                        can = false;
                        break;
                    } else if (S[i][j] == '0' && B[c][j] == '1') {
                        cnt_chng++;
                    }
                }
                if (can && k >= cnt_chng) {
                    last = max(last, {cnt_chng, c});
                }
            }
            ans[i] = (last.second + '0');
            k -= last.first;
        }
    }
    if (k) {
        cout << -1;
    } else {
        cout << ans;
    }
}