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
#define str string
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
        int m = 0;
        for (int i = 0; i < n - 1; i++) {
            if (A[i] != -1 && A[i + 1] != -1) {
                m = max(m, abs(A[i] - A[i + 1]));
            }
        }
        int m1 = -1e10, m2 = 1e10;
        for (int i = 0; i < n; i++) {
            if (A[i] != -1) {
                if ((i > 0 && A[i - 1] == -1) || (i < n && A[i + 1] == -1)) {
                    m1 = max(m1, A[i]);
                    m2 = min(m2, A[i]);
                }
            }
        }
        int k = (m1 + m2) / 2;
        m = max(m, m1 - k);
        m = max(m, k - m2);
        cout << m << ' ' << k << '\n';
    }
}