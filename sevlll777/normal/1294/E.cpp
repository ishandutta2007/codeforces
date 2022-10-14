#pragma GCC optimize("O3")
#pragma GCC target("avx2")
#pragma GCC optimize("fast-math")
#pragma GCC optimize("unrool-loops")
#pragma GCC optimize("no-stack-limit")
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
#define pii pair<int, int>
#define tupint tuple<int, int, int>
#define tupint2 tuple<int, int, int, int>
#define str string
using namespace std;
const int M = 1000000007;


signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n, m;
    cin >> n >> m;
    vector<vector<int>> A(n);
    vector<vector<int>> stolb(m);
    for (int i = 0; i < n; i++) {
        vector<int> B(m);
        for (int j = 0; j < m; j++) {cin >> B[j]; stolb[j].pb(B[j]);}
        A.pb(B);
    }
    int ans = 0;
    for (int i = 0; i < m; i++) {
        vector<int> kek(n);
        for (int j = 0; j < n; j++) {
            if ((m + stolb[i][j] - i-1) % m == 0 && stolb[i][j] <= m * (n - 1) + i+1) {
                kek[(n + j - (stolb[i][j] - i-1) / m) % n]++;
            }
        }
        int lol = 1e9;
        for (int id = 0; id < n; id++) {
            lol = min(lol, id + n - kek[id]);
        }
        ans += lol;
    }
    cout << ans;

}