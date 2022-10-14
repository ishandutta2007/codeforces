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
    int n, m;
    cin >> n >> m;
    vector<int> A(m);
    for (int i = 0; i < m; i++) cin >> A[i];
    vector<vector<int>> sosedi(n + 1);
    int ans = 0;
    for (int i = 1; i < m; i++) {
        if (A[i - 1] != A[i]) {
            sosedi[A[i]].pb(A[i - 1]);
            sosedi[A[i - 1]].pb(A[i]);
            ans += abs(A[i] - A[i - 1]);
        }
    }
    int s = ans;
    for (int i = 1; i <= n; i++) {
        if (!sosedi[i].empty()) {
            int suum = 0;
            sort(sosedi[i].begin(), sosedi[i].end());
            for (auto num : sosedi[i]) {
                suum += abs(num - i);
            }
            int mid = sosedi[i][sosedi[i].size() / 2];
            int sosum = 0;
            for (auto num : sosedi[i]) {
                sosum += abs(num - mid);
            }
            ans = min(ans, s + sosum - suum);
        }
    }
    cout << ans << '\n';

}