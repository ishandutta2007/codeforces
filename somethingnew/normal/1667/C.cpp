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

signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    int res = 0;
    int n;
    cin >> n;
    int od = 0, ev = 0;
    while (1) {
        if (od >= ev)
            ev++;
        else
            od++;
        if (od + ev + max(od, ev) >= n) {
            break;
        }
    }
    cout << od + ev << '\n';
    int add1 = (od == ev);
    if (od == ev)
        ev--;
    for (int i = 0; i < od; ++i) {
        cout << i + 1 << ' ' << od - i << '\n';
    }
    for (int i = 0; i < ev; ++i) {
        cout << i + od + 1 << ' ' << ev - i + od << '\n';
    }
    if (add1)
        cout << od + ev + 1 << ' ' << od + ev + 1 << '\n';
}
/*
1
 5
 3 -3 -2 3 -2

 */