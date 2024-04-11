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
const int C = 2e5+1e4;
int D[2 * C + 100];
int D2[2 * C + 100];
int a, b, k, t;

void refresh() {
    int sum = 0;
    for (int i = -C; i <= C; i++) {
        sum += D[C + i];
        sum %= M;
        if (C + i >= 2 * k + 1) {
            sum += M;
            sum -= D[C + i - 2 * k - 1];
        }
        sum %= M;
        if (C + i - k >= 0) {
            D2[C + i - k] = sum;
        }
    }
    for (int i = -C; i <= C; i++) {
        D[C + i] = D2[C + i];
    }
}

signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> a >> b >> k >> t;
    t *= 2;
    D[C + a - b] = 1;
    while (t--) {
        refresh();
    }
    int ans = 0;
    for (int i = 1; i <= C; i++) {
        ans += D[C + i];
        ans %= M;
    }
    cout << ans;
}