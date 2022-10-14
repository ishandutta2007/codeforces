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
#include <random>
#include <queue>
#include <bitset>

#define pb push_back
#define int long long
#define str string
using namespace std;


signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int t;
    cin >> t;
    while (t--) {
        int n, x;
        cin >> n >> x;
        vector<int> A(n);
        for (int i = 0; i < n; i++) cin >> A[i];
        A.pb(0);
        sort(A.begin(), A.end());
        for (int i = 1; i <= n; i++) A[i] += A[i - 1];
        int ans = 0;
        for (int i = 0; i < n; i++) {
            if (A.back() - A[i] >= x * (n - i)) {
                ans = n - i;
                break;
            }
        }
        cout << ans << '\n';
    }
}