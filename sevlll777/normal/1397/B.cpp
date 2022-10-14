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
const int M = 1000000007;

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int n;
    cin >> n;
    vector<int> A(n);
    int ans = 2e18;
    int c = 1;
    for (int i = 0; i < n; i++) cin >> A[i];
    sort(A.begin(), A.end());
    while (pow(c, n) <= 1e14) {
        int kek = 0;
        int gg = 1;
        for (int i = 0; i < n; i++) {
            kek += abs(A[i] - gg);
            gg *= c;
        }
        c++;
        ans = min(ans, kek);
    }
    cout << ans << '\n';
}