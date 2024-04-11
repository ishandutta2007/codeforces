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
        int n, k;
        cin >> n >> k;
        vector<int> A(n);
        for (int i = 0; i < n; i++) cin >> A[i];
        for (int i = 1; i < n; i++) A[i] -= A[0];
        A[0] = 0;
        if (k == 1 && A[n - 1] != 0) {
            cout << -1;
        } else if (k == 1) {
            cout << 1;
        } else {
            int dif = 1;
            for (int i = 1; i < n; i++) {
                if (A[i] != A[i - 1]) dif++;
            }
            if (dif <= k) {
                cout << 1;
            } else {
                dif -= k;
                cout << 1 + (dif + k - 2) / (k - 1);
            }
        }
        cout << '\n';
    }

}