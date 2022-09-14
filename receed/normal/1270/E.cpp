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
    vector<int> x(n), y(n);
    rep(i, n) 
        cin >> x[i] >> y[i];
    for (int i = n - 1; i >= 0; i--) {
        x[i] -= x[0];
        y[i] -= y[0];
    }
    while (1) {
        int g = 0;
        rep(i, n)
            g = __gcd(g, __gcd(x[i], y[i]));
        int f1 = 0;
        rep(i, n) {
            x[i] /= g;
            y[i] /= g;
            if ((x[i] + y[i]) % 2)
                f1 = 1;
        }
        if (f1)
            break;
        rep(i, n) {
            int nx = (x[i] + y[i]) / 2, ny = (x[i] - y[i]) / 2;
            x[i] = nx;
            y[i] = ny;
        }
    }
    vector<int> a;
    rep(i, n)
        if ((x[i] + y[i]) % 2)
            a.push_back(i);
    cout << a.size() << '\n';
    for (int i : a)
        cout << i + 1 << ' ';
}