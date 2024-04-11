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
#include <bits/stdc++.h>

#define pb push_back
#define int long long
#define ld long double
using namespace std;
const int M = 1000000007;
const long double eps = 1e-6;

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int t;
    cin >> t;
    while (t--) {
        int n, l;
        cin >> n >> l;
        vector<int> A(n);
        for (int i = 0; i < n; i++) cin >> A[i];
        vector<int> D(n + 2);
        D[1] = A[0];
        for (int i = 1; i < n; i++) D[i + 1] = A[i] - A[i - 1];
        D[n + 1] = l - A[n - 1];
        vector<long double> P(n + 2), Q(n + 3);
        P[1] = D[1];
        for (int i = 2; i <= n + 1; i++) P[i] = P[i - 1] + (1.0 * D[i] / i);
        Q[n + 1] = D[n + 1];
        for (int i = n; i >= 1; i--) Q[i] = Q[i + 1] + (1.0 * D[i] / (n + 2 - i));
        for (int i = 1; i <= n + 1; i++) {
            long double left = P[i - 1];
            long double right = Q[i + 1];
            long double d = right - left;
            d *= i;
            d *= (n + 2 - i);
            d += D[i] * i;
            d /= (n + 2);
            long double x = d;
            if (-eps <= x && x <= D[i]+eps) {
                cout << fixed << setprecision(17) << left + x / i;
                break;
            }

        }
        cout << '\n';
    }

}