#pragma GCC optimize("O3")
#pragma GCC target("avx2")
#pragma GCC optimize("fast-math")
#pragma GCC optimize("unrool-loops")
#pragma GCC optimize("no-stack-limit")

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

signed main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    str s; cin >> s;
    int q; cin >> q;
    vector<vector<int>> pep(26, {0});
    for (int i = 0; i < s.size(); i++) {
        for (int x = 0; x < 26; x++) {
            if (x == s[i] - 'a') {
                pep[x].pb(pep[x].back() + 1);
            } else {
                pep[x].pb(pep[x].back());
            }
        }
    }
    while (q--) {
        int l, r; cin >> l >> r;
        if (r == l) {
            cout << "Yes\n";
        } else {
            if (s[l - 1] == s[r - 1]) {
                int cnt = 0;
                bool chc = false;
                for (int h = 0; h < 26; h++) {
                    if (pep[h][r] - pep[h][l - 1]) cnt++;
                }
                if (cnt <= 2) {
                    cout << "No\n";
                } else {
                    cout << "Yes\n";
                }
            } else {
                cout << "Yes\n";
            }
        }
    }
}