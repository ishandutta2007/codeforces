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

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int n;
    cin >> n;
    vector<int> A(n);
    for (int i = 0; i < n; i++) cin >> A[i];
    int ans = A[0] * (n - A[0] + 1);
    for (int i = 1; i < n; i++) {
        int x = A[i - 1], y = A[i];
        if (y >= x) {
            ans += (y - x) * (n - y + 1);
        } else {
            ans += y * (x - y);
        }
    }
    cout << ans << '\n';
}