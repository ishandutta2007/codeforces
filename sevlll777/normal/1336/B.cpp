#define _GLIBCXX_DEBUG

#include <iostream>
#include <iomanip>
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

// #define int long long
#define ll long long
#define dbl long double
#define pb push_back
#define str string
using namespace std;
const int M = 1e9 + 7;

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int t;
    cin >> t;
    while (t--) {
        int a, b, c;
        cin >> a >> b >> c;
        vector<ll> A(a), B(b), C(c);
        for (int i = 0; i < a; i++) cin >> A[i];
        for (int i = 0; i < b; i++) cin >> B[i];
        for (int i = 0; i < c; i++) cin >> C[i];
        if (A.size() > B.size()) {
            swap(A, B);
            swap(a, b);
        }
        if (A.size() > C.size()) {
            swap(A, C);
            swap(a, c);
        }
        sort(A.begin(), A.end());
        sort(B.begin(), B.end());
        sort(C.begin(), C.end());
        ll ans = (ll) 3e18 + 2020;
        int y1 = 0;
        int z1 = 0;
        for (auto x : A) {
            while (y1 < (int) B.size() && B[y1] <= x) y1++;
            for (auto i : {y1 - 1, y1}) {
                if (0 <= i && i < b) {
                    ll s = (x + B[i]) / 2;
                    while (z1 < C.size() && C[z1] < s) z1++;
                    for (auto j : {z1 - 1, z1}) {
                        if (0 <= j && j < c) {
                            ans = min(ans, (x - B[i]) * (x - B[i]) + (x - C[j]) * (x - C[j]) +
                                           (B[i] - C[j]) * (B[i] - C[j]));
                        }
                    }
                }
            }
        }
        swap(B, C);
        swap(b, c);
        y1 = 0;
        z1 = 0;
        for (auto x : A) {
            while (y1 < (int) B.size() && B[y1] <= x) y1++;
            for (auto i : {y1 - 1, y1}) {
                if (0 <= i && i < b) {
                    ll s = (x + B[i]) / 2;
                    while (z1 < C.size() && C[z1] < s) z1++;
                    for (auto j : {z1 - 1, z1}) {
                        if (0 <= j && j < c) {
                            ans = min(ans, (x - B[i]) * (x - B[i]) + (x - C[j]) * (x - C[j]) +
                                           (B[i] - C[j]) * (B[i] - C[j]));
                        }
                    }
                }
            }
        }
        cout << ans << '\n';
    }
}