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
    vector<int> A(n), B(n), C(m), D(m);
    for (int i = 0; i < n; i++) cin >> A[i] >> B[i];
    for (int i = 0; i < m; i++) cin >> C[i] >> D[i];
    vector<tuple<int, int, pair<int, int>>> suka;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            suka.pb({C[j] - A[i] + 1, -1 - D[j] + B[i], {i, j}});
        }
    }
    sort(suka.begin(), suka.end());
    vector<int> heh(n * m + 1);
    for (int i = 0; i < n * m; i++) {
        heh[i] = max(0LL, 1 + D[get<2>(suka[i]).second] - B[get<2>(suka[i]).first]);
    }
    for (int i = n * m - 2; i >= 0; i--) {
        heh[i] = max(heh[i], heh[i + 1]);
    }
    int ans = heh[0];
    for (int i = 0; i < n * m; i++) {
        int mah = max(0LL, get<0>(suka[i])) + heh[i + 1];
        ans = min(ans, mah);
    }
    cout << ans << '\n';
}