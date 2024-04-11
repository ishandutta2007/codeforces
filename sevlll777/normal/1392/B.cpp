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

#define int long long
#define pb push_back
using namespace std;

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
        vector<int> B = A;
        sort(B.begin(), B.end());
        k %= 2;
        if (k == 0) {
            for (auto x : A) {
                cout << x - B[0] << ' ';
            }
        } else {
            for (auto x : A) {
                cout << B[n - 1] - x << ' ';
            }
        }
        cout << '\n';
    }
}