#include <iostream>
#include "cmath"
#include "string"
#include "vector"
#include "set"
#include "algorithm"
#include "map"
#include "queue"
#include "array"
#include "numeric"
using namespace std;
#define all(x) x.begin(), x.end()
multiset<int> elel;
vector<pair<int, int>> zp;
void azp(int x, int y) {
    if (x < y)
        swap(x, y);
    zp.push_back({x, y});
    elel.erase(elel.find(x));
    elel.erase(elel.find(y));
    elel.insert(x+y);
    elel.insert(x-y);
}
void bzp(int x) {
    zp.push_back({x, 0});
    zp.push_back({x, x});
    elel.erase(elel.find(x));
    elel.insert(x*2);
}
void clk(int n, int t) {
    if (n <= 2)
        return;
    int stp = 1;
    while (stp < n)
        stp *= 2;
    stp /= 2;
    for (int i = stp + 1; i <= min(n, stp * 2 - 1); ++i) {
        azp(i*t, t * (stp + stp - i));
    }
    int k1 = stp + stp - min(n, stp * 2 - 1) - 1;
    int k2 = min(n, stp * 2 - 1) - stp;
    clk(k1, t);
    clk(k2, t * 2);
}
void solve() {
    int n;
    cin >> n;
    if (n == 2) {
        cout << "-1\n";
        return;
    }
    int stp = 1;
    while (stp < n)
        stp *= 2;
    elel.clear();
    zp.clear();
    for (int i = 0; i < n; ++i) {
        elel.insert(i + 1);
    }
    clk(n, 1);
    int x = -1;
    for (auto i : elel) {
        if (i == 0) {
            x = 0;
            break;
        }
        if (elel.count(i) >= 2) {
            x = i;
            break;
        }
    }
    if (x == -1)
        exit(1);
    if (x != 0) {
        azp(x, x);
    }
    while (*elel.begin() == 0) {
        azp(0, stp);
    }
    zp.pop_back();
    while (*elel.begin() != stp) {
        bzp(*elel.begin());
    }
    zp.push_back({0, stp});
    cout << zp.size() << '\n';
    for (auto i : zp)
        cout << i.first << ' ' << i.second << '\n';
}

signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n;
    cin >> n;
    while (n--) solve();
}