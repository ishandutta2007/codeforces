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
using namespace std;
int a, b, c, t, d, n, m, k, x, r, j2, l, q, i, j, v1, v2, p, y, w, l2, r2, m2, x1, x2;
string s;
const int M = 1e9 + 7;

signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> n;
    int codd = 0;
    vector<int> A;
    for (int i = 0; i < n; i++) {
        cin >> x;
        A.pb(x);
        if (abs(x) % 2 == 1) {
            codd++;
        }
    }
    codd /= 2;
    for (auto x : A) {
        if (abs(x) % 2 == 0) {
            cout << x / 2 << '\n';
        } else {
            if (codd > 0) {
                if (x > 0) {
                    cout << x / 2 + 1 << '\n';
                } else {
                    cout << x / 2 << '\n';
                }
                codd--;
            } else {
                if (x > 0) {
                    cout << x / 2 << '\n';
                } else {
                    cout << x / 2 - 1 << '\n';
                }
            }
        }
    }
    return 0;
}