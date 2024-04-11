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
// #define int long long
#define ld long double
using namespace std;

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    string a, b;
    cin >> a >> b;
    if (a.size() != b.size()) {
        cout << "NO\n";
        exit(0);
    }
    bool is1 = false, iis1 = false;
    for (auto c : a) is1 |= (c == '1');
    for (auto c : b) iis1 |= (c == '1');
    if ((is1 && iis1) || a == b) {
        cout << "YES\n";
    } else {
        cout << "NO\n";
    }
}