#include <bits/stdc++.h>

using namespace std;

using ll = long long;
using ull = unsigned long long;
using ld = long double;

#define all(a) (a).begin(), (a).end()
#define mp make_pair

template<typename T1, typename T2> 
inline void chkmin(T1& x, const T2& y) {
    if (y < x) x = y;
}

template<typename T1, typename T2>
inline void chkmax(T1& x, const T2& y) {
    if (x < y) x = y;
}

signed main() {
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    cout.precision(20), cout.setf(ios::fixed);
    int n;
    cin >> n;
    vector<pair<int, int>> one, two;
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            if ((i + j) % 2) {
                one.push_back({i, j});
            } else {
                two.push_back({i, j});
            }
        }
    }
    while (!one.empty() && !two.empty()) {
        int x;
        cin >> x;
        if (x == 1) {
            cout << 2 << " " << two.back().first + 1 << " " << two.back().second + 1 << endl;
            two.pop_back();
        } else {
            cout << 1 << " " << one.back().first + 1 << " " << one.back().second + 1 << endl;
            one.pop_back();
        }
    }
    pair<int, int> colors;
    vector<pair<int, int>> a;
    if (one.empty()) {
        colors = {2, 3};
        a = two;
    } else {
        colors = {1, 3};
        a = one;
    }
    while (!a.empty()) {
        int x;
        cin >> x;
        int myColor;
        if (x == colors.first) {
            myColor = colors.second;
        } else {
            myColor = colors.first;
        }
        cout << myColor << " " << a.back().first + 1 << " " << a.back().second + 1 << endl;
        a.pop_back();
    }
    return 0;
}