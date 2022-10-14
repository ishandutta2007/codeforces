#define __GLIBCXX_DEBUG

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

#define pb push_back
// #define int long long
#define dbl long double
#define str string
using namespace std;
const int M = 1e9 + 7;
map<int, int> g;
map<int, vector<int>> gt;
bitset<10000005> used;
map<int, int> TYPE;

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int t;
    cin >> t;
    while (t--) {
        g = {};
        gt = {};
        TYPE = {};
        used.reset();
        int n, m;
        cin >> n >> m;
        int c = m + 1;
        vector<string> color(n);
        for (int i = 0; i < n; i++) cin >> color[i];
        vector<string> field(n);
        for (int i = 0; i < n; i++) cin >> field[i];
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                used[c*i+j] = false;
                if (field[i][j] == 'L') {
                    g[c*i+j] = c*i+j-1;
                    gt[c*i+j-1].pb(c*i+j);
                } else if (field[i][j] == 'R') {
                    g[c*i+j] = c*i+j+1;
                    gt[c*i+j+1].pb(c*i+j);
                } else if (field[i][j] == 'U') {
                    g[c*i+j] = c*i-c+j;
                    gt[c*(i-1)+j].pb(c*i+j);
                } else {
                    g[c*i+j] = c*i+c+j;
                    gt[c*(i+1)+j].pb(c*i+j);
                }
            }
        }

        int ans1 = 0, ans2 = 0;

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (!used[c*i+j]) {
                    vector<int> koz = {};
                    int now = c*i+j;
                    while (!used[now]) {
                        used[now] = true;
                        koz.pb(now);
                        now = g[now];
                    }
                    int y = -1;
                    for (int h = 0; h < koz.size(); h++) {
                        if (koz[h] == now) {
                            y = h;
                            break;
                        }
                    }
                    if (y != -1) {
                        for (int h = 0; h < y; h++) used[koz[h]] = false;
                        vector<int> CCL;
                        for (int h = y; h < koz.size(); h++) CCL.pb(koz[h]);
                        ans1 += CCL.size();
                        vector<char> CAN(CCL.size(), '1');
                        for (int w = 0; w < CCL.size(); w++) {
                            if (color[CCL[w]/c][CCL[w]%c] == '0') {
                                CAN[w] = '0';
                            }
                            int tp = w;
                            TYPE[CCL[w]] = tp;
                            deque<int> lol = {CCL[w]};
                            while (!lol.empty()) {
                                int huy = lol.front();
                                lol.pop_front();
                                for (auto yy : gt[huy]) {
                                    if (!used[yy]) {
                                        used[yy] = true;
                                        lol.pb(yy);
                                        TYPE[yy] = ((int) (CCL.size() + TYPE[huy] - 1)) % ((int) CCL.size());
                                        if (color[yy/c][yy%c] == '0') {
                                            CAN[TYPE[yy]] = '0';
                                        }
                                    }
                                }
                            }
                        }
                        for (auto x : CAN) ans2 += (x == '0');
                    }
                }
            }
        }

        cout << ans1 << ' ' << ans2 << '\n';
    }
}