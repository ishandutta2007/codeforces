#pragma GCC optimize("Ofast,fast-math,unroll-loops,inline,no-stack-protector")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,sse4.1,sse4.2,avx,avx2,abm,mmx,popcnt")

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

using namespace std;
#define pb push_back
#define int long long

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int n, x, y;
    cin >> n >> x >> y;
    string s;
    cin >> s;
    int cnt = 0;
    for (int i = 0; i < n; i++) {
        if (s[i] == '0' && (i == 0 || s[i - 1] == '1')) cnt++;
    }
    if (cnt == 0) {
        cout << 0;
    } else {
        cout << y + min(x, y) * (cnt - 1);
    }
}