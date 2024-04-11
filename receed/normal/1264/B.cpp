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

vector<int> go(int a, int b, int c, int d, int f) {
    if (a < 0 || b < 0 || c < 0 || d < 0)
        return {};
    vector<int> r {f};
    while (a || b || c || d) {
        if (f == 2) {
            if (a) {
                r.push_back(1);
                f = 1;
                a--;
            }
            else if (c) {
                r.push_back(3);
                f = 3;
                c--;
            }
            else
                return {};
        }
        else if (f == 3) {
            if (d) {
                r.push_back(4);
                f = 4;
                d--;
            }
            else if (b) {
                r.push_back(2);
                f = 2;
                b--;
            }
            else
                return {};
        }
        else if (f == 1) {
            if (!b)
                return {};
            r.push_back(2);
            f = 2;
            b--;
        }
        else if (f == 4) {
            if (!c)
                return {};
            r.push_back(3);
            f = 3;
            c--;
        }
    }
    return r;
}

int main() {
#ifdef ONPC
    freopen("a.in", "r", stdin);
#endif
    ios_base::sync_with_stdio(0); cin.tie(0);
    int a, b, c, d;
    cin >> a >> b >> c >> d;
    vector<int> ans = go(a - 1, b, c, d, 1);
    if (ans.empty())
        ans = go(a, b - 1, c, d, 2);
    if (ans.empty())
        ans = go(a, b, c - 1, d, 3);
    if (ans.empty())
        ans = go(a, b, c, d - 1, 4);
    if (ans.empty())
        cout << "NO\n";
    else {
        cout << "YES\n";
        for (int i : ans)
            cout << i - 1 << ' ';
    }
}