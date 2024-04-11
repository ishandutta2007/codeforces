// #define _GLIBCXX_DEBUG

#include <iostream>
#include <iomanip>
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
#include <random>
#include <queue>
#include <bitset>

#define int long long
#define dbl long double
#define pb push_back
#define str string
using namespace std;
const int M = 998244353;


signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        if (n % 4 == 2) {
            cout << "NO\n";
        } else {
            cout << "YES\n";
            vector<int> X(n / 2);
            vector<int> Y(n / 2);
            for (int i = 0; i < n / 2 - 1; i++) {
                X[i] = i + 1;
                Y[i] = i + 1;
            }
            X.back() = 2 * n +1  + n / 4;
            Y.back() = 2 * n + 1;
            for (auto p : X) cout << 2*p << ' ';
            for (auto p : Y) cout << 1+2*p << ' ';
            cout << '\n';
        }


    }

}