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
#define pii  pair<int, int>
#define pdd pair<double, double>
#define pdi pair<double, int>
#define unmp unordered_map
#define unst unordered_set
#define tupint tuple<int, int, int>
#define pib pair<int, bool>
#define dbl long double
#define str string
#define psi pair<str, int>
using namespace std;
const int M = 998244353;

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int t; cin >> t;
    while (t-- ) {
        int n; cin >> n;
        map<str, set<int>> kek;
        for (int _ = 0; _ < n; _++) {
            str s; cin >> s; kek[s].insert(_);
        }
        vector<str> ans(n);
        int cnt = 0;
        set<char> used;
        for (auto p : kek) {
            if (p.second.size() == 1) {
                int z = 0; for (auto g : p.second) z = g;
                ans[z] = p.first;
            } else {
                while (p.second.size() > 1) {
                    int ind = 0; for (auto g : p.second) ind = g;
                    cnt++;
                    set<char> dig = {'0', '1', '2', '3', '4', '5', '6', '7', '8', '9'};
                    for (auto z : kek) {
                        dig.erase(z.first[0]);
                    }
                    for (auto ch : used) {
                        dig.erase(ch);
                    }
                    str d = p.first;
                    char ff;
                    for (auto dg : dig) ff = dg;
                    d[0] = ff;
                    used.insert(ff);
                    ans[ind] = d;
                    p.second.erase(ind);
                }
                int z = 0; for (auto g : p.second) z = g;
                ans[z] = p.first;
            }
        }
        cout << cnt << '\n';
        for (auto y : ans) {
            cout << y << '\n';
        }
    }
}