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

// #define int long long
#define dbl long double
#define pb push_back
#define str string
using namespace std;
const int M = 998244353;

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int n, k;
    cin >> n >> k;
    vector<pair<int, int>> kek;
    for (int i = 0; i < k; i++) {
        int a, b;
        cin >> a >> b;
        kek.pb({min(a, b), max(a, b)});
    }
    sort(kek.begin(), kek.end());
    for (int x = 1; x < n; x++) {
        if (n % x == 0) {
            vector<pair<int, int>> sas;
            for (auto p : kek) {
                int a = p.first, b = p.second;
                a += x;
                b += x;
                if (a > n) {
                    a -= n;
                }
                if (b > n) {
                    b -= n;
                }
                sas.pb({min(a, b), max(a, b)});
            }
            sort(sas.begin(), sas.end());
            if (sas == kek) {
                cout << "Yes";
                return 0;
            }
        }
    }
    cout << "No";

}