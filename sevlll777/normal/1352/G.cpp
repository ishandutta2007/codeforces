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
#include <queue>
#include <bitset>

#define pb push_back
// #define int long long
using namespace std;

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        if (n <= 3) {
            cout << -1 << '\n';
        } else {
            int b = n / 4 - 1;
            for (int j = 0; j < b; j++) {
                cout << 4 * j + 2 << ' ' << 4 * j + 4 << ' ' << 4 * j + 1 << ' ' << 4 * j + 3 << ' ';
            }
            if (n % 4) {
                cout << 4 * b + 1 << ' ';
                if (n % 4 == 1) {
                    cout << n - 2 << ' ' << n << ' ' << n - 3 << ' ' << n - 1 << '\n';
                } else if (n % 4 == 2) {
                    cout << n - 2 << ' ' << n - 4 << ' ' << n - 1 << ' ' << n - 3 << ' ' << n << '\n';
                } else if (n % 4 == 3) {
                    cout << n - 4 << ' ' << n - 1 << ' ' << n - 5 << ' ' << n - 3 << ' ' << n << ' ' << n - 2 << '\n';
                }
            } else {
                cout << n - 2 << ' ' << n << ' ' << n - 3 << ' ' << n - 1 << '\n';
            }
        }
    }

}