#include <algorithm>
#include <chrono>
#include <cmath>
#include <ctime>
#include <iomanip>
#include <iostream>
#include <iterator>
#include <map>
#include <queue>
#include <random>
#include <set>
#include <stack>
#include <string>
#include <utility>
#include <vector>
#include <cassert>
#include <assert.h>

#pragma GCC optimize("O3")

using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;

const ll MOD = 1000000007;
const ld EPS = 1e-11;
const ld MEPS = EPS * 1e2;
const ll INFL = 1e18;
const int INF = 2e9 + 7;
const ld PI = acos(-1);
const ld E = exp(1);

mt19937 rnd((unsigned)chrono::steady_clock::now().time_since_epoch().count());

int mod;

int sum(int a, int b) {
    int ans = a + b;
    while (ans >= mod) {
        ans -= mod;
    }
    return ans;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    //    freopen("input.txt", "r", stdin);
    //    freopen("output.txt", "w", stdout);

    int n;
    cin >> n >> mod;

    vector<vector<int>> fa({ { 0, 0, 1, 0 }, { 0, 0, 0, 0 }, { 0, 0, 0, 0 }, { 0, 0, 0, 0 } });
    vector<vector<int>> fb({ { 0, 1, 0, 0 }, { 0, 0, 0, 0 }, { 0, 0, 0, 0 }, { 0, 0, 0, 0 } });
    vector<vector<int>> ff({ { 0, 0, 0, 0 }, { 0, 0, 0, 0 }, { 0, 0, 0, 0 }, { 0, 0, 0, 0 } });

    for (int k = 3; k <= n; ++k) {
        vector<vector<int>> nfa(k + 1, vector<int>(k + 1, 0)), nfb(nfa), nff(nfa);
        for (int t = 0; t <= (k >> 1); ++t) {
            //cout << t << endl;
            for (int x = 1; x + t <= k; ++x) {
                nfa[t][x] = sum(nfa[t][x - 1], fa[t][x - 1]);
                nfa[t][x] = sum(nfa[t][x], fb[t][x - 1]);
                nfa[t][x] = sum(nfa[t][x], ff[t][x - 1]);
            }
            for (int x = k - 1 - t; x > 0; --x) {
                nfb[t][x] = sum(nfb[t][x + 1], fb[t][x]);
                nfb[t][x] = sum(nfb[t][x], ff[t][x]);
            }
            if (t > 0) {
                for (int x = k - t; x > 0; --x) {
                    nff[t][x] = fa[t - 1][k - t];
                }
            }
        }
        /*for (int i = 1; i <= k; ++i) {
            cout << nfa[0][i] << " ";
        } cout << endl;
        for (int i = 1; i <= k; ++i) {
            cout << nfb[0][i] << " ";
        } cout << endl;
        for (int i = 1; i <= k; ++i) {
            cout << nff[0][i] << " ";
        } cout << endl;
        for (int i = 1; i <= k; ++i) {
            cout << nfa[1][i] << " ";
        } cout << endl;
        for (int i = 1; i <= k; ++i) {
            cout << nfb[1][i] << " ";
        } cout << endl;
        for (int i = 1; i <= k; ++i) {
            cout << nff[1][i] << " ";
        } cout << endl;*/
        fa = move(nfa);
        fb = move(nfb);
        ff = move(nff);
    }

    int ans = 0;
    for (int t = 0; t < n; ++t) {
        for (int i = 0; i <= n; ++i) {
            ans = sum(ans, fa[t][i]);
            ans = sum(ans, fb[t][i]);
            ans = sum(ans, ff[t][i]);
        }
    }

    cout << ans << "\n";

    return 0;
}