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
const int M = 1000000007;

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int n;
    cin >> n;
    vector<int> A(n), cost(n), kek;
    int sq = 0;
    for (int i = 0; i < n; i++) {
        cin >> A[i];
        int s = (int) round(sqrt(A[i]));
        if (s * s == A[i]) {
            sq++;
            kek.pb(1 + (A[i] == 0));
        }
        cost[i] = min({abs(A[i] - (s - 1) * (s - 1)), abs(A[i] - s * s), abs(A[i] - (s + 1) * (s + 1))});
    }
    int ans = 0;
    if (sq < n / 2) {
        sort(cost.begin(), cost.end());
        for (int i = 0; i < n / 2; i++) ans += cost[i];
        cout << ans << '\n';
    } else {
        sort(kek.begin(), kek.end());
        if (sq >= n / 2) {
            for (int i = 0; i < sq - n / 2; i++) ans += kek[i];
        }
        cout << ans << '\n';
    }
}