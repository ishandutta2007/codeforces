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
    int n, s;
    cin >> n >> s;
    if (n == 1) {
        if (s == 1) {
            cout << "NO\n";
        } else {
            cout << "YES\n" << s << "\n1";
        }
        return 0;
    }
    if (n <= (s - n - 1)) {
        cout << "YES\n";
        for (int i = 0; i < n - 1; i++) cout << "1 ";
        cout << s - (n - 1) << '\n' << n;
    } else if (s == 2 * n) {
        cout << "YES\n";
        for (int i = 0; i < n; i++) cout << "2 ";
        cout << "\n1";
    } else {
        cout << "NO\n";
    }

}