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
        vector<int> A(n), B(n);

        for (int i = 0; i < n; i++) {
            cin >> A[i];
            B[i] = A[i];
        }
        sort(B.begin(), B.end());
        for (int i = 0; i < n; i++) {
            A[i] = (int) (lower_bound(B.begin(), B.end(), A[i]) - B.begin());
        }
        vector<int> index(n);
        for (int i = 0; i < n; i++) {
            index[A[i]] = i;
        }
        int cnt = 0, ans = 0;
        for (int i = 1; i < n; i++) {
            if (index[i] > index[i - 1]) {
                cnt++;
                ans = max(ans, cnt);
            } else {
                cnt = 0;
            }
        }
        cout << n - ans - 1 << '\n';
    }
}