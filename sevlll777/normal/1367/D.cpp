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
#define ld long double
using namespace std;

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int t;
    cin >> t;
    while (t--) {
        string s;
        cin >> s;
        map<char, int> cnt;
        for (auto c : s) cnt[c]++;
        int lol = 0;
        int m;
        cin >> m;
        vector<int> B(m);
        for (int i = 0; i < m; i++) cin >> B[i];
        int n = (int) s.size();
        string ans = "";
        for (int _ = 0; _ < m; _++) ans += '0';
        vector<int> finally;
        char kek = 'z';
        while (finally.size() < m) {
            vector<int> fff;
            for (int i = 0; i < m; i++) {
                if (ans[i] == '0') {
                    int h = 0;
                    for (auto jj : finally) {
                        h += abs(i - jj);
                    }
                    if (h == B[i]) {
                        fff.pb(i);
                    }
                }
            }
            while (cnt[kek] < fff.size()) kek--;
            cnt[kek] -= fff.size();
            for (auto num : fff) {
                finally.pb(num);
                ans[num] = kek;
            }
            kek--;
        }
        cout << ans + '\n';
    }
}