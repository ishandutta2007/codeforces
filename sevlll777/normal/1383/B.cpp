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
        vector<int> A(n);
        for (int i = 0; i < n; i++) cin >> A[i];
        int x = 0;
        for (auto num : A) x ^= num;
        if (x == 0) {
            cout << "DRAW";
        } else {
            int bit = (int) floor(log2(x));
            int o = 0, z = 0;
            for (auto num : A) {
                if ((num >> bit) % 2) {
                    o++;
                } else {
                    z++;
                }
            }
            if ((o % 4 == 1) || (z % 2 == 1)) {
                cout << "WIN";
            } else {
                cout << "LOSE";
            }
        }
        cout << '\n';
    }
}