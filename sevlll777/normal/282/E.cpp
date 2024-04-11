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
#define int long long
#define ld long double
using namespace std;
int xex;

int solve(vector<int> A, vector<int> B, int bit) {
    if (bit < 0 || A.empty() || B.empty()) return 0;
    vector<int> odA, odB, zeA, zeB;
    for (auto x : A) {
        if ((x >> bit) & 1) {
            odA.pb(x);
        } else {
            zeA.pb(x);
        }
    }
    for (auto x : B) {
        if ((x >> bit) & 1) {
            odB.pb(x);
        } else {
            zeB.pb(x);
        }
    }
    if (!((xex >> bit) & 1)) {
        int mrg = 0;
        int f = 0;
        if (!odA.empty() && !zeB.empty()) {
            f = (1LL << bit);
            mrg = max(mrg, solve(odA, zeB, bit - 1));
        }
        if (!odB.empty() && !zeA.empty()) {
            f = (1LL << bit);
            mrg = max(mrg, solve(odB, zeA, bit - 1));
        }
        if (f != 0) {
            return f + mrg;
        }
        return solve(A, B, bit - 1);
    } else {
        int mrg = 0;
        int f = 0;
        if (!odA.empty() && !odB.empty()) {
            f = (1LL << bit);
            mrg = max(mrg, solve(odA, odB, bit - 1));
        }
        if (!zeB.empty() && !zeA.empty()) {
            f = (1LL << bit);
            mrg = max(mrg, solve(zeB, zeA, bit - 1));
        }
        if (f != 0) {
            return f + mrg;
        }
        return solve(A, B, bit - 1);
    }
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int n;
    cin >> n;
    vector<int> P = {0};
    for (int i = 0; i < n; i++) {
        int x;
        cin >> x;
        P.pb(P.back() ^ x);
    }
    xex = P.back();
    cout << solve(P, P, 60) << '\n';
}