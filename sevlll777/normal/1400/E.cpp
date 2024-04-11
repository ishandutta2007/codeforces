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
// #define int long long
#define ld long double
using namespace std;
const int M = 1000000007;
vector<int> A;

int solve(int l, int r) {
    int ans = 0;
    int mi = 1e9+11;
    for (int j = l; j < r; j++) {
        mi = min(mi, A[j]);
    }
    if (mi == 0) {
        while (A[l] == 0 && l < r) l++;
        int ll = l;
        for (int x = l+1; x < r; x++) {
            if (A[x] == 0 && A[x - 1] != 0) {
                ans += solve(ll, x);
            }
            if (A[x] != 0 && A[x - 1] == 0) {
                ll = x;
            }
        }
        if (A[r - 1] != 0) {
            ans += solve(ll, r);
        }
        return ans;
    }
    ans = r - l;
    int t2 = mi;
    for (int x = l; x < r; x++) A[x] -= mi;
    t2 += solve(l, r);
    for (int x = l; x < r; x++) A[x] += mi;
    return min(ans, t2);
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int n;
    cin >> n;
    A.resize(n);
    for (int i = 0; i < n; i++) cin >> A[i];
    cout << solve(0, n) << '\n';
}