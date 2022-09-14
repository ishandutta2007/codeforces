#include <iostream>
#include <cstdio>
#include <iomanip>
#include <cstring>
#include <cmath>
#include <cassert>
#include <bitset>
#include <string>
#include <vector>
#include <deque>
#include <queue>
#include <map>
#include <set>
#include <unordered_map>
#include <unordered_set>
#include <algorithm>
#define rep(i, n) for (int i = 0; i < (n); i++)
#define all(a) (a).begin(), (a).end()
#define rall(a) (a).rbegin(), (a).rend()
using ll = long long;
using ld = long double;
using namespace std;

int main() {
#ifdef ONPC
    freopen("a.in", "r", stdin);
#endif
    int n, x = 0, y = 0, z = 0;
    cin >> n;
    vector<int> r(n), b(n);
    rep(i, n)
        cin >> r[i];
    rep(i, n) {
        cin >> b[i];
        if (r[i] && b[i])
            z++;
        else if (r[i])
            x++;
        else if (b[i])
            y++;
    }
    if (!x) {
        cout << -1;
        return 0;
    }
    cout << max(0, y / x) + 1;

}