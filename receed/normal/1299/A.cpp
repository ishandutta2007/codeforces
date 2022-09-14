#include <iostream>
#include <iomanip>
#include <cstdio>
#include <vector>
#include <algorithm>
#include <cmath>
#include <cstring>
#include <cassert>
#include <string>
#include <set>
#include <map>
#include <random>
#include <bitset>
#include <string>
#include <unordered_set>
#include <unordered_map>
#include <deque>
#include <queue>
#define rep(i, n) for (int i = 0; i < (n); i++)
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()

using namespace std;
using ll = long long;
using ul = unsigned long long;
using ld = long double;

int main() {
#ifdef ONPC
    freopen("a.in", "r", stdin);
#endif
    ios_base::sync_with_stdio(0); cin.tie(0);
    int n;
    cin >> n;
    vector<int> a(n), b(n + 1), c(n + 1);
    b[0] = c[n] = (1 << 30) - 1;
    rep(i, n) {
        cin >> a[i];
        b[i + 1] = b[i] & ~a[i];
    }
    int ans = -1, ca, x = 0;
    for (int i = n - 1; i >= 0; i--) {
        c[i] = c[i + 1] & ~a[i];
        ca = a[i] & b[i] & c[i + 1];
        if (ca > ans) {
            ans = ca;
            x = i;
        }
    }
    swap(a[0], a[x]);
    rep(i, n)
        cout << a[i] << ' ';
}