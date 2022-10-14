#pragma GCC optimize("unroll-loops")

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
#define pii pair<int, int>
#define pdd pair<double, double>
#define pdi pair<double, int>
#define unmp unordered_map
#define unst unordered_set
#define tupint tuple<int, int, int>
#define pib pair<int, bool>
#define dbl long double
#define str string
#define psi pair<str, int>
using namespace std;
const int M = 998244353;

signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n;
    cin >> n;
    vector<int> kek(n + 3, 1);
    int color = 1;
    for (int p = 2; p * p <= n + 2; p++) {
        if (kek[p] == 1) {
            for (int j = 2 * p; j <= n + 2; j += p) {
                kek[j] = 2;
            }
        }
    }
    if (n > 2) {
        cout << "2\n";
    } else {
        cout << "1\n";
    }
    for (int i = 2; i <= n + 1; i++) {
        cout << kek[i] << ' ';
    }

}