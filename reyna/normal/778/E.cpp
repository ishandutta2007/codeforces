// In the name of God

#include <iostream>
#include <algorithm>
#include <fstream>
#include <vector>
#include <deque>
#include <assert.h>
#include <queue>
#include <stack>
#include <set>
#include <map>
#include <stdio.h>
#include <string.h>
#include <utility>
#include <math.h>
#include <bitset>
#include <iomanip>

using namespace std;

const int N = (int) 2e3 + 5, mod = (int) 0;

string b[N];
int n, cnt[N], cost[N], dp[N], odp[N], lord[N], ord[N], c[N], tmp[N];
char ch[N];
void radix_sort(int len) {
    memset(c, 0, sizeof c);
    for (int j = 0; j < n; ++j) {
        ch[j] = (b[lord[j]].size() < len? '0': b[lord[j]][b[lord[j]].size() - len]);
        c[ch[j] - '0']++;
    }
//    if (len <= 3)
    for (int j = 1; j <= 10; ++j) {
        c[j] += c[j - 1];
       // cout << j << ' ' << c[j] << ' ' << c[j - 1] << endl;
    }
    for (int j = 0; j < n; ++j) ord[--c[ch[j] - '0']] = lord[j];
    reverse(ord, ord + n);
}

int32_t main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    string a;
    cin >> a;
    cin >> n;
    for (int j = 0; j < n; ++j) {
        cin >> b[j];
        string t = "";
        int pl = 0;
        while (b[j][pl] == '0') pl++;
        for (int x = pl; x < (int) b[j].size(); ++x)
            t += b[j][x];
        b[j] = t;
        ord[j] = j;
    }
    for (int j = 0; j < 10; ++j) cin >> cost[j];
    for (int j = 0; j < N; ++j) dp[j] = -2e9;
    dp[0] = 0;
    for (int len = 1; len <= 1005; ++len) {
        for (int j = 0; j < N; ++j) {
            lord[j] = ord[j];
            odp[j] = dp[j];
            dp[j] = -2e9;
        }
        radix_sort(len);
        memset(cnt, 0, sizeof cnt);
        for (int j = 0; j < n; ++j) {
            if (len <= b[j].size() || len <= a.size()) {
                cnt[(b[j].size() >= len? b[j][b[j].size() - len]: '0') - '0']++;
            }
        }
        for (int use = 0; use <= n; ++use) {
            for (int dig = (len == a.size()); dig <= (len <= a.size()) * 9; ++dig) {
                if (len <= a.size() && a[a.size() - len] != '?' && a[a.size() - len] - '0' != dig) continue;
                int nx_use = 0, csum = 0;
                for (int j = 0; j <= 10; ++j) {
                    if (j + dig >= 10) {
                        nx_use += cnt[j];
                    }
                    csum += (cnt[j] * cost[(j + dig) % 10]);
                }
                dp[nx_use] = max(dp[nx_use], odp[use] + csum);
                
            }
            if (use == n) continue;
            int ind = lord[use];
            if (b[ind].size() >= len || a.size() >= len) {
                char x = (b[ind].size() >= len? b[ind][b[ind].size() - len]: '0');
                cnt[x - '0']--;
                cnt[x - '0' + 1]++;
            } else {
                cnt[1]++;
            }
        }
    }
    cout << dp[0] << '\n';
}