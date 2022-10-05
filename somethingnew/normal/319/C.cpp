#include <iostream>
#include <vector>
#include "stack"
#include <algorithm>
#include <cmath>
#include <set>
#include <queue>
#include "bitset"
#include "iomanip"
#include <random>
#include "climits"
#include "map"
#include "cassert"
//#pragma GCC optimise("O3")
//#pragma GCC optimise("unroll-loops")
#define int long long
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
using namespace std;
const int INF = 1e9;
const int N = 1e5 + 179;

struct line {
    int k = 0, b = 0;
    explicit line(int k, int b) : k(k), b(b) {}
    int get(int x) const {
        return k * x + b;
    }
};

vector<line> lines;
vector<int> dots;

int cross(line a, line b) {
    int x = (b.b - a.b) / (a.k - b.k);
    if (b.b < a.b)
        x--;
    return x;
}


void add(line cur) {
    while (!lines.empty() && cross(lines.back(), cur) <= dots.back()) {
        lines.pop_back();
        dots.pop_back();
    }
    if (lines.empty())
        dots.push_back(-INF);
    else  dots.push_back(cross(lines.back(), cur));
    lines.push_back(cur);
    if (dots.size() >= 2) {
        if (dots.back() < dots[dots.size() - 2])
            exit(1);
    }
}

int get(int x) {
    return lines[max((int)(lower_bound(dots.begin(), dots.end(), x) - dots.begin() - 1), 0ll)].get(x);
}

signed main() {
    //freopen("file.in", "r", stdin);
    //freopen("file.out", "w", stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.precision(20);
    cout.setf(ios::fixed);
    int n; cin >> n;
    vector<int> a(n), b(n), dp(n);
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }
    for (int i = 0; i < n; ++i) {
        cin >> b[i];
    }
    dp[0] = 0;
    add(line(b[0], dp[0]));
    for (int i = 1; i < n; ++i) {
        dp[i] = get(a[i]);
        add(line(b[i], dp[i]));
    }
    cout << dp[n - 1] << endl;

    return 0;
}