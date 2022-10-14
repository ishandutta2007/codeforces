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
    int k;
    cin >> k;
    int l = -1;
    int r = 1e8;
    while (r - l > 1) {
        int m = (l + r) / 2;
        int num = m / 10;
        int r0 = m % 10;
        int kek = 1;
        int y = 1;
        while (kek <= k && y <= 10) {
            kek *= (num + 1);
            y++;
        }
        if (kek >= k) {
            r = m;
        } else {
            int g = 1;
            for (int h = 0; h < 10 - r0; h++) {
                g *= (num + 1);
            }
            for (int h = 0; h < r0; h++) {
                g *= (num + 2);
            }
            if (g >= k) {
                r = m;
            } else {
                l = m;
            }
        }
    }
    int ad = l + 1;
    int num = ad / 10;
    int r0 = ad % 10;
    string s = "codeforces";
    for (auto c : s) {
        if (r0) {
            for (int _ = 0; _ < num + 2; _++) cout << c;
            r0--;
        } else {
            for (int _ = 0; _ < num + 1; _++) cout << c;
        }
    }
}