#pragma GCC optimize("Ofast,fast-math,unroll-loops,inline,no-stack-protector")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,sse4.1,sse4.2,avx,avx2,abm,mmx,popcnt")

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

using namespace std;
#define pb push_back
#define int long long

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int t;
    cin >> t;
    while (t--) {
        int n, k;
        cin >> n >> k;
        vector<int> A(n), B(n);
        for (int i = 0; i < n; i++) cin >> A[i];
        for (int i = 0; i < n; i++) cin >> B[i];
        sort(A.begin(), A.end());
        sort(B.begin(), B.end());
        reverse(A.begin(), A.end());
        reverse(B.begin(), B.end());
        int ans = 0;
        int l = 0, r = 0;
        while (l + r < n) {
            if (r == k || A[l] > B[r]) {
                ans += A[l++];
            }  else {
                ans += B[r++];
            }
        }
        cout << ans << '\n';
    }


}