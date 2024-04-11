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
        vector<vector<int>> indexes(n + 1);
        for (int i = 0; i < n; i++) {
            indexes[A[i]].pb(i);
        }
        vector<int> kekw(n + 7, 1e18);
        for (int h = 1; h <= n; h++) {
            int now = -1;
            int heh = 0;
            for (auto c : indexes[h]) {
                heh = max(heh, c - now);
                now = c;
            }
            heh = max(heh, n - now);
            kekw[heh] = min(kekw[heh], h);
        }
        int mem = 1e18;
        for (int i = 1; i <= n; i++) {
            mem = min(mem, kekw[i]);
            if (mem == 1e18) {
                cout << "-1 ";
            } else {
                cout << mem << ' ';
            }
        }
        cout << '\n';
    }

}