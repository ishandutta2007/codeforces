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
int A[200009], P[200009];

int ans(int l, int r) {
    if (l + 1 >= r) return 0;
    int m = (l + r) / 2;
    int answ = ans(l, m) + ans(m + 1, r);
    vector<bool> cand(r - l + 2, false);
    vector<int> C1, C2;
    int s = 0;
    for (int x = m; x >= l; x--) {
        if (A[x] >= s / 2) {
            cand[x - l] = true;
            C1.pb(x);
        }
        s += A[x];
    }
    s = 0;
    for (int x = m + 1; x <= r; x++) {
        if (A[x] >= s / 2) {
            cand[x - l] = true;
            C2.pb(x);
        }
        s += A[x];
    }
    int keku = 0;
    for (auto x : C1) {
        for (int y = m + 1; y <= r; y++) {
            if (abs(x - y) >= 2 && ((A[x] ^ A[y]) == (P[max(x, y) - 1] - P[min(x, y)]))) {
                answ++;
                if (cand[y - l]) keku++;
            }
        }
    }
    for (auto x : C2) {
        for (int y = l; y <= m; y++) {
            if (abs(x - y) >= 2 && ((A[x] ^ A[y]) == (P[max(x, y) - 1] - P[min(x, y)]))) {
                answ++;
                if (cand[y - l]) keku++;
            }
        }
    }
    answ -= keku / 2;
    return answ;
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int n;
    cin >> n;
    for (int i = 0; i < n; i++) cin >> A[i];
    for (int i = 1; i < n; i++) P[i] = P[i - 1] + A[i];
    cout << ans(0, n - 1) << '\n';
}