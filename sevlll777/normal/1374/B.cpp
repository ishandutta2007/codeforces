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
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        int c2 = 0, c3 = 0;
        while (n % 2 == 0) {
            n /= 2;
            c2++;
        }
        while (n % 3 == 0) {
            n /= 3;
            c3++;
        }
        if (n != 1) {
            cout << "-1\n";
        } else {
            if (c3 < c2) {
                cout << "-1\n";
            } else {
                cout << (c3 - c2) + c3 << '\n';
            }
        }
    }

}