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
    vector<int> A(n), D(n);
    for (int i = 0; i < n; i++) cin >> A[i];
    for (int i = 0; i < n; i++) cin >> D[i];
    int sumA = 0;
    for (auto x : A) sumA += x;
    if (k == 0) {
        for (int j = n - 2; j >= 0; j--) A[j] += A[j + 1];
        int ans = 0;
        for (int i = 0; i < n; i++) {
            ans = max(ans, -D[i] + A[i]);
        }
        cout << ans << '\n';
        exit(0);
    }
    if (k == 1) {
        int ans = 0;
        ans = max(ans, A[n - 1] - D[n - 1]);
        int sus = 0;
        int mem = 1e18;
        for (int i = 0; i < n - 1; i++) {
            sus += A[i];
            mem = min(mem, D[i]);
        }
        ans = max(ans, sus - mem + max(0LL, A[n - 1] - D[n - 1]));
        int bruh = 0;
        for (int i = n - 1; i >= 1; i--) {
            bruh += A[i];
            ans = max(ans, bruh - D[i]);
        }
        int meme = 1e18;
        for (int i = 1; i < n; i++) meme = min(meme, A[i]);
        ans = max(ans, sumA - meme - D[0]);
        vector<int> DD;
        for (int i = 0; i < n - 1; i++) DD.pb(D[i]);
        sort(DD.begin(), DD.end());
        ans = max(ans, sumA - DD[0] - DD[1]);
        cout << ans << '\n';
        exit(0);
    }
    int ans = 0;
    int minD = 1e18;
    for (int i = 0; i < n - 1; i++) minD = min(minD, D[i]);
    ans = max(ans, sumA - minD);
    ans = max(ans, A[n - 1] - D[n - 1]);
    cout << ans << '\n';

}