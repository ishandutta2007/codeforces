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
    ios_base::sync_with_stdio(0); cin.tie(0);
    int n, x, y, inf = 2e6, lx = inf, rx = -1, ly = inf, ry = -1, ls = inf, rs = -inf;
    cin >> n;
    string s;
    rep(i, n) {
        cin >> s;
        x = y = 0;
        for (char c : s) {
            if (c == 'B')
                x++;
            else
                y++;
        }
        lx = min(lx, x);
        ly = min(ly, y);
        ls = min(ls, x - y);
        rx = max(rx, x);
        ry = max(ry, y);
        rs = max(rs, x - y);
    }
    int l = -1, r = inf, m, ax, ay, cx;
    while (r - l > 1) {
        m = (l + r) / 2;
        for (int i = max(lx, rx - m); i <= min(lx + m, rx); i++) {
            int cly = max(ly, max(ry - m, i - (ls + m)));
            if (i + cly == 0)
                cly = 1;
            if (cly <= ly + m && i - cly >= rs - m) {
                r = m;
                ax = i;
                ay = cly;
                break;
            }
        }
        if (r != m)
            l = m;
    }
    cout << r << '\n';
    rep(i, ax)
        cout << 'B';
    rep(i, ay)
        cout << 'N';
}