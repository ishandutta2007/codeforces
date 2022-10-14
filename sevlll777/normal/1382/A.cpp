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
const int M = 1000000007;

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int t0;
    cin >> t0;
    while (t0--) {
        int n, m;
        cin >> n >> m;
        vector<int> A(n);
        for (int i = 0; i < n; i++) cin >> A[i];
        int f = 0;
        while (m--) {
            int x;
            cin >> x;
            for (int i = 0; i < n; i++) {
                if (A[i] == x && !f) {
                    cout << "YES\n1 " << x << "\n";
                    f = 1;
                }
            }
        }
        if (!f) cout << "NO\n";

    }

}