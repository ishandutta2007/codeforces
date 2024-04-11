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
    int t;
    cin >> t;
    while (t--) {
        int n, k;
        cin >> n >> k;
        string s;
        cin >> s;
        if (k == 1) {
            sort(s.begin(), s.end());
            cout << s << '\n';
        } else {
            sort(s.begin(), s.end());
            string ans = "";
            ans += s[k - 1];
            if (s[0] != s[k - 1]) {
                cout << ans << '\n';
            } else {
                vector<int> cnt(26);
                for (int c = k; c < n; c++) {
                    cnt[s[c] - 'a']++;
                }
                int kek = 0;
                for (int h = 0; h < 26; h++) {
                    if (cnt[h]) kek++;
                }
                if (kek >= 2) {
                    for (int c = k; c < n; c++) ans += s[c];
                } else {
                    for (int h = 0; h < 26; h++) {
                        if (cnt[h]) {
                            int x = (cnt[h] + k - 1) / k;
                            for (int y = 0; y < x; y++) ans += h + 'a';
                        }
                    }
                }
                cout << ans << '\n';
            }
        }
    }
}