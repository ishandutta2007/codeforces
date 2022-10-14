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
        int n;
        cin >> n;
        vector<int> A(n + 2, 1);
        A[n + 1] = -1;
        for (int i = 0; i < n; i++) cin >> A[i];
        for (int i = 0; i <= n+1; i++) {
            if (A[i] != 1) {
                if (i % 2 == 0) {
                    cout << "First\n";
                } else {
                    cout << "Second\n";
                }
                break;
            }
        }

    }

}