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

void Solve() {
    int n, k;
    cin >> n >> k;
    vector<int> a(n);
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }

    vector<int> b(a);
    int x, y;
    GetBestB(b, n, k, x, y);

    vector<int> lb, rb;
    int cl = 0;
    for (int iter = 0; iter < k; ++iter) {
        int cr = cl - 1;
        int in_g{ 0 }, in_b{ 0 };
        while (in_g <= in_b) {
            ++cr;
            if (a[cr] >= x && a[cr] <= y) {
                ++in_g;
            }
            else {
                ++in_b;
            }
        }
        lb.push_back(cl + 1);
        rb.push_back(cr + 1);
        cl = cr + 1;
    }
    rb.back() = n;

    cout << x << " " << y << "\n";
    for (int i = 0; i < k; ++i) {
        cout << lb[i] << " " << rb[i] << "\n";
    }
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
    cin >> t;
    for (int q = 0; q < t; ++q) {
        Solve();
    }

    return 0;
}