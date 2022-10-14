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
const int M = 998244353;

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int n, k;
    cin >> n >> k;
    vector<int> A(n);
    for (int i = 0; i < n; i++) cin >> A[i];
    sort(A.begin(), A.end());
    if (A[0] <= k + 1) {
        cout << A[0] << '\n';
        exit(0);
    }
    vector<int> cnt(3000009);
    for (auto x : A) cnt[x]++;
    for (int i = 1; i <= 3000005; i++) cnt[i] += cnt[i - 1];
    for (int d = A[0]; d >= k + 1; d--) {
        bool ok = true;
        for (int x = d; x <= 1000005+d; x += d) {
            if (cnt[x - 1] != cnt[x - d + k]) {
                ok = false;
                break;
            }
        }
        if (ok) {
            cout << d << '\n';
            exit(0);
        }
    }
}