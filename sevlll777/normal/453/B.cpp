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
#include <bitset>

#define pb push_back
// #define int long long
#define ld long double
using namespace std;
const int M = 1000000007;

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int n;
    cin >> n;
    vector<int> P = {2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31, 37, 41, 43, 47, 53};
    vector<int> masks(60);
    for (int num = 2; num < 59; num++) {
        for (int i = 0; i < P.size(); i++) {
            if (num % P[i] == 0) {
                masks[num] += (1 << i);
            }
        }
    }
    vector<int> mask_answer((1 << 16) + 1, -1);
    mask_answer[0] = 0;
    pair<int, int> par[n + 1][(1 << 16) + 1];
    for (int i = 1; i <= n; i++) {
        int a;
        cin >> a;
        vector<int> mask_answer_2((1 << 16) + 1, -1);
        for (int last = 1; last < 59; last++) {
            for (int mask = 0; mask < (1 << P.size()); mask++) {
                if ((mask & masks[last]) == masks[last]) {
                    int mmm = mask - masks[last];
                    if (mask_answer[mmm] != -1) {
                        if (mask_answer_2[mask] == -1) {
                            mask_answer_2[mask] = mask_answer[mmm] + abs(a - last);
                            par[i][mask] = {mmm, last};
                        } else {
                            if (mask_answer_2[mask] > mask_answer[mmm] + abs(a - last)) {
                                mask_answer_2[mask] = mask_answer[mmm] + abs(a - last);
                                par[i][mask] = {mmm, last};
                            }
                        }
                    }
                }
            }
        }
        mask_answer = mask_answer_2;
    }
    pair<int, int> kekw = {1e9, 1e9};
    for (int p = 0; p < (1 << 16); p++) {
        if (mask_answer[p] != -1) {
            kekw = min(kekw, {mask_answer[p], p});
        }
    }
    int maska = kekw.second;
    int i = n;
    vector<int> B;
    while (i > 0) {
        B.pb(par[i][maska].second);
        maska = par[i][maska].first;
        i--;
    }
    reverse(B.begin(), B.end());
    for (auto x : B) cout << x << ' ';

}