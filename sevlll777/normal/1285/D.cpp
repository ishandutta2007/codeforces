#pragma GCC optimize("unroll-loops")

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
#define pii pair<int, int>
#define tupint tuple<int, int, int>
#define tupint2 tuple<int, int, int, int>
#define str string
using namespace std;
const int M = 1e9 + 7;
vector<int> po = {1};

int solve(vector<int> A) {
    if(A.size() <= 1) {
        return 0;
    }
    int m = 0;
    for (auto p : A) m = max(m, p);
    if (m == 0) {
        return 0;
    }
    if (m == 1) {
        for (auto p : A) {
            if (p == 0) {
                return 1;
            }
        }
        return 0;
    }
    int z = floor(log2(m));
    vector<int> l1;
    vector<int> l2;
    for (auto y : A) {
        if (y < pow(2, z)) {
            l1.pb(y);
        } else {
            l2.pb(y - po[z]);
        }
    }
    if (!l1.empty() && !l2.empty()) {
        return po[z] + min(solve(l1), solve(l2));
    } else if (l1.empty()) {
        return solve(l2);
    } else {
        return solve(l1);
    }
}

signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n;
    cin >> n;
    for (int i = 0; i < 35; i++) {
        po.pb(po.back() * 2);
    }
    vector<int> A(n);
    int x = 0;
    int m = 0;
    for (int i = 0; i < n; i++) {
        cin >> A[i];
    }
    cout << solve(A);


}