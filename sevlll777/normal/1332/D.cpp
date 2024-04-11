// #define _GLIBCXX_DEBUG
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
#define str string
using namespace std;

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int k;
    cin >> k;
    cout << "4 4\n";
    int s = 131072;
    cout << k + s << ' ' << k + s << ' ' << k + s << ' ' << k + s << '\n';
    cout << k + s << ' ' << k + s << ' ' << k + s << ' ' << k << '\n';
    cout << 0 << ' ' << 0 << ' ' << s << ' ' << k + s << '\n';
    cout << 0 << ' ' << 0 << ' ' << 0 << ' ' << k << '\n';
}