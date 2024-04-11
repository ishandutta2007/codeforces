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
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        int zo = 0, oz = 0;
        for (int i =0 ; i < n; i++) {
            int x;
            cin >> x;
            if (x % 2 != i % 2) {
                if (x % 2 == 0) {
                    oz++;
                } else {
                    zo++;
                }
            }
        }
        if (oz != zo) {
            cout << "-1\n";
        } else {
            cout << oz << '\n';
        }
    }
}