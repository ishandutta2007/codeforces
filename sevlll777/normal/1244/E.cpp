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
int a, b, c, d, n, m, k, x, r, l, q, i, j, v1, v2, p, y, w, l2, r2, m2, x1, x2;
int cnt;
string s, t;
const int M = 1e9 + 7;
vector<int> A;

int kul(int x) {
    cnt = 0;
    for (int j = 0; j < n; j++) {
        if (A[j] < x) {
            cnt += x - A[j];
        } else if (A[j] > x + m) {
            cnt += A[j] - x - m;
        }
    }
    return cnt;
}

signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> n >> k;
    for (int i = 0; i < n; i++) {
        cin >> x;
        A.pb(x);
    }
    sort(A.begin(), A.end());
    l = -1;
    r = 1e9 + 20;
    while (r - l > 1) {
        m = (l + r) / 2;
        l2 = -1;
        r2 = 1e9 + 20;
        while (r2 - l2 > 2) {
            p = l2 + (r2 - l2) / 3;
            q = l2 + 2 * (r2 - l2) / 3;
            x1 = kul(p);
            x2 = kul(q);
            if (x1 > x2) {
                l2 = p;
            } else if (x2 > x1) {
                r2 = q;
            } else {
                l2 = p;
                r2 = q;
            }
        }
        if (kul(l2 + 1) <= k) {
            r = m;
        } else {
            l = m;
        }
    }
    cout << l + 1;
}