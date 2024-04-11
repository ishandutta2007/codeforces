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
    int n, m;
    cin >> n >> m;
    if (n > m) swap(n, m);
    if (n == 2 && m != 7 && m >= 4) {
        cout << n * m - (n * m) % 2 << '\n';
        exit(0);
    }
    if (n == 3 && m >= 3) {
        cout << n * m - (n * m) % 2 << '\n';
        exit(0);
    }
    if (n % 6 == 2 && m % 6 == 2 && n >= 8 && m >= 8) {
        cout << n * m << '\n';
        exit(0);
    }
    int n2 = n, m2 = m;
    n2 %= 6;
    m2 %= 6;
    int ans = n * m - n2 * m2;
    if (n2 > m2) swap(n2, m2);
    if (n2 == 1) {
        if (m2 == 4) {
            ans += 2;
        } else if (m2 == 5) {
            ans += 4;
        }
    } else if (n2 == 2) {
        if (m2 == 3) {
            ans += 4;
        } else if (m2 == 4) {
            ans += 8;
        } else if (m2 == 5) {
            ans += 10;
        }
    } else if (n2 == 3) {
        if (m2 == 3) {
            ans += 8;
        } else if (m2 == 4) {
            ans += 12;
        } else if (m2 == 5) {
            ans += 14;
        }
    } else if (n2 == 4) {
        if (m2 == 4) {
            ans += 16;
        } else if (m2 == 5) {
            ans += 20;
        }
    } else if (n2 == 5) {
        ans += 24;
    }
    cout << ans << '\n';


}