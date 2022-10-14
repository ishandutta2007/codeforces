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
#define pdd pair<double, double>
#define pdi pair<double, int>
#define unmp unordered_map
#define unst unordered_set
#define tupint tuple<int, int, int>
#define pib pair<int, bool>
#define dbl long double
using namespace std;
const int M = 1e9 + 7;
int m, x0, x1, yg0, yg1;

bool comp(pii a, pii b) {
    x0 = a.first;
    x1 = a.second;
    yg0 = b.first;
    yg1 = b.second;
    if ((x1 < m) && (yg1 >= m)) {
        return true;
    } else if ((x1 >= m) && (yg1 < m)) {
        return false;
    } else if (x0 < yg0) {
        return true;
    } else {
        return false;
    }
}

signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int q;
    cin >> q;
    for (int i = 0; i < q; i++) {
        int n, s;
        cin >> n >> s;
        vector<pii> Z;
        for (int _ = 0; _ < n; _++) {
            int l, r;
            cin >> l >> r;
            Z.pb({l, r});
        }
        int left = 0;
        int right = 10000000020;
        while (right - left > 1) {
            m = (left + right) / 2;
            sort(Z.begin(), Z.end(), comp);
            int s_ = 0;
            bool f = true;
            for (int el = 0; el < n; el++) {
                if (el >= n / 2) {
                    if (Z[el].second >= m) {
                        s_ += max(m, Z[el].first);
                    } else {
                        f = false;
                        break;
                    }
                } else {
                    s_ += Z[el].first;
                }
                if (s_ > s) {
                    f = false;
                    break;
                }
            }
            if (s_ > s) {
                f = false;
            }
            if (f) {
                left = m;
            } else {
                right = m;
            }
        }
        cout << left << '\n';
    }
    return 0;
}