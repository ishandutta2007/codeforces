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
#define int long long
#define pii pair<int, int>
#define tupint tuple<int, int, int>
#define tupint2 tuple<int, int, int, int>
#define str string
using namespace std;
const int M = 1e9 + 7;

signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n;
    cin >> n;
    if (n == 1) {
        cout << "1 1";
        return 0;
    }
    map<int, int> factor;
    int n2 = n;
    while (n2 % 2 == 0) {
        n2 /= 2;
        factor[2]++;
    }
    int p = 3;
    while (p * p - 1 <= n) {
        while (n2 % p == 0) {
            n2 /= p;
            factor[p]++;
        }
        p += 2;
    }
    if (n2 > 1) {
        factor[n2]++;
    }
    vector<int> heh;
    for (auto p : factor) {
        heh.pb(p.first);
    }
    int hjh = 1e13;
    int huh = 1e13;
    for (int x = 0; x < pow(2, heh.size()); x++) {
        int f1 = 1;
        for (int i = 0; i < heh.size(); i++) {
            if ((x >> i) % 2 == 1) {
                f1 *= pow(heh[i], factor[heh[i]]);
            }
        }
        int f2 = n / f1;
        if (max(f1, f2) < hjh) {
            hjh = max(f1, f2);
            huh = min(f1, f2);
        }
    }
    cout << huh << ' ' << hjh;


}