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
const int M = 998244353;
pair<int, int> p1[81][81], p2[81][81], p3[81][81], p4[81][81], p5[81][81];
int n, k;
vector<vector<int>> allth = {{}};

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    cin >> n >> k;
    vector<int> fr(n);
    vector<vector<int>> cost(n, fr);
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> cost[i][j];
        }
    }
    for (int s = 0; s < n; s++) {
        for (int f = 0; f < n; f++) {
            vector<pair<int, int>> pot;
            for (int h = 0; h < n; h++) {
                if (h != s && h != f) {
                    pot.pb({cost[s][h] + cost[h][f], h});
                }
            }
            sort(pot.begin(), pot.end());
            if (pot.size() >= 1) {
                p1[s][f] = pot[0];
            }
            if (pot.size() >= 2) {
                p2[s][f] = pot[1];
            }
            if (pot.size() >= 3) {
                p3[s][f] = pot[2];
            }
            if (pot.size() >= 4) {
                p4[s][f] = pot[3];
            }
            if (pot.size() >= 5) {
                p5[s][f] = pot[4];
            }
        }
    }
    int ans = 1e17;
    bitset<100> lol;
    vector<int> p;
    for (int f1 = 0; f1 < n; f1++) {
        for (int f2 = 0; f2 < n; f2++) {
            for (int f3 = 0; f3 < n; f3++) {
                for (int f4 = 0; f4 < n; f4++) {
                    p = {};
                    if (k / 2 - 1 >= 1) p.pb(f1);
                    if (k / 2 - 1 >= 2) p.pb(f2);
                    if (k / 2 - 1 >= 3) p.pb(f3);
                    if (k / 2 - 1 >= 4) p.pb(f4);
                    p.pb(0);
                    lol.reset();
                    for (auto x : p) lol[x] = true;
                    int costx = 0;
                    int last = 0;
                    for (int i = 0; i < k / 2; i++) {
                        if (!lol[p1[last][p[i]].second]) {
                            costx += p1[last][p[i]].first;
                        } else if (!lol[p2[last][p[i]].second]) {
                            costx += p2[last][p[i]].first;
                        } else if (!lol[p3[last][p[i]].second]) {
                            costx += p3[last][p[i]].first;
                        } else if (!lol[p4[last][p[i]].second]) {
                            costx += p4[last][p[i]].first;
                        } else if (!lol[p5[last][p[i]].second]) {
                            costx += p5[last][p[i]].first;
                        }
                        last = p[i];
                    }
                    ans = min(ans, costx);
                }
            }
        }
    }
    cout << ans;

}