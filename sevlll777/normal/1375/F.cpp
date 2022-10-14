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
#include <bitset>

#define pb push_back
#define int long long
#define ld long double
using namespace std;
const int M = 1000000007;

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int a, b, c;
    cin >> a >> b >> c;
    cout << "First" << endl;
    for (int _ = 0; _ < 2; _++) {
        int g = 3 * max({a, b, c}) - a - b - c;
        cout << g << endl;
        int ans;
        cin >> ans;
        if (ans == 1 && a != max({a, b, c})) {
            cout << max({a, b, c}) - (a + b + c - a - max({a, b, c})) << endl;
            int ad;
            cin >> ad;
            if (ad <= 0) exit(0);
        } else if (ans == 2 && b != max({a, b, c})) {
            cout << max({a, b, c}) - (a + b + c - b - max({a, b, c})) << endl;
            int ad;
            cin >> ad;
            if (ad <= 0) exit(0);
        } else if (ans == 3 && c != max({a, b, c})) {
            cout << max({a, b, c}) - (a + b + c - c - max({a, b, c})) << endl;
            int ad;
            cin >> ad;
            if (ad <= 0) exit(0);
        } else {
            if (ans == 1) {
                a += g;
            } else if (ans == 2) {
                b += g;
            } else {
                c += g;
            }
        }
    }
}