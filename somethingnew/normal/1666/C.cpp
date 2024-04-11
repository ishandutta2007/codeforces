#include <iostream>
#include "vector"
#include "algorithm"
#include "numeric"
#include "climits"
#include "iomanip"
#include "bitset"
#include "cmath"
#include "map"
#include "deque"
#include "array"
#include "set"
#define all(x) x.begin(), x.end()
using namespace std;
vector<array<int, 4>> lines;
void addl(int x1, int y1, int x2, int y2) {
    if (x1 == x2 and y1 == y2)
        return;
    lines.push_back({x1,y1,x2,y2});
}
signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    vector<pair<int, int>> p(3);
    vector<int> Y;
    for (auto &[x, y] : p) {
        cin >> x >> y;
        Y.push_back(y);
    }
    sort(all(p));
    sort(all(Y));
    addl(p[0].first, Y[1], p[2].first, Y[1]);
    addl(p[0].first, p[0].second, p[0].first, Y[1]);
    addl(p[1].first, p[1].second, p[1].first, Y[1]);
    addl(p[2].first, p[2].second, p[2].first, Y[1]);
    cout << lines.size() << '\n';
    for (auto [x1,y1,x2,y2] : lines)
        cout << x1 << ' ' << y1 << ' ' << x2 << ' ' << y2 << '\n';
    
}