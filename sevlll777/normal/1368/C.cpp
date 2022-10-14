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
#define int long long
#define ld long double
using namespace std;


signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int n;
    cin >> n;
    cout << 3 * (n + 1) + 1 << '\n';
    cout << "0 0\n";
    for (int i = 1; i <= n + 1; i++) {
        cout << i << ' ' << i << '\n';
        cout << i - 1 << ' ' << i << '\n';
        cout << i << ' ' << i - 1 << '\n';
    }
}