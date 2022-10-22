#pragma GCC optimize("O3")

#include <algorithm>
#include <bitset>
#include <chrono>
#include <cmath>
#include <cstdint>
#include <cstdio>
#include <cstring>
#include <ctime>
#include <iomanip>
#include <iostream>
#include <iterator>
#include <map>
#include <numeric>
#include <queue>
#include <random>
#include <set>
#include <stack>
#include <stdio.h>
#include <string>
#include <unordered_map>
#include <utility>
#include <vector>
#include <cassert>
#include <assert.h>

using namespace std;

typedef int64_t ll;
typedef uint64_t ull;
typedef long double ld;

const ll MOD = 1000000007;
const ld EPS = 1e-11;
const ld INFLD = 1e20;
const ll INFL = 4e18;
const int INF = 2e9 + 7;
const ld PI = acos(-1);
const ld E = exp(1);

const ll MAXF = 2000500;

//mt19937 rnd((unsigned)chrono::steady_clock::now().time_since_epoch().count());
mt19937 rnd(643896);

double ReadDouble() {
    string s;
    cin >> s;
    return stol(s);
}

void Print(vector<int>& a, vector<int>& b) {
    for (int i = 0; i < a.size(); ++i) {
        cout << a[i] << " " << b[i] << "\n";
    }
}

void GetBestB(vector<int>& b, int n, int k, int& fin_l, int& fin_r) {
    fin_l = 1, fin_r = n;
    sort(b.begin(), b.end());

    int cl = 0, cr = 0;
    while (cr + 1 < n - cr - 1 + k) {
        ++cr;
    }
    while (cr < n) {
        if (b[cr] - b[cl] < fin_r - fin_l) {
            fin_r = b[cr];
            fin_l = b[cl];
        }
        ++cl;
        ++cr;
    }
}

// true if updated c_right
bool Fill(const vector<int>& rest, int& filled, int& c_left, int& c_right) {
    int r_most = c_right;
    for (int i = c_left + 1; i < c_right; ++i) {
        ++filled;
        r_most = max(r_most, rest[i]);
    }
    if (r_most > c_right) {
        c_left = c_right;
        c_right = r_most;
        return true;
    }
    return false;
}

void Solve() {
    int n;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }
    vector<int> rest(n);
    vector<int> resv(n + 1, -1);
    for (int i = n - 1; i >= 0; --i) {
        resv[a[i]] = max(resv[a[i]], i);
        rest[i] = resv[a[i]];
    }

    int filled = 0;
    int c_left = 0;
    while (c_left < n) {
        int c_right = rest[c_left];
        while (true) {
            if (!Fill(rest, filled, c_left, c_right)) {
                c_left = c_right + 1;
                break;
            }
        }
    }

    cout << filled << "\n";
}

int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

#ifdef LOCAL
    freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
#endif // LOCAL

    int t = 1;
    //cin >> t;
    for (int q = 0; q < t; ++q) {
        Solve();
    }

    return 0;
}