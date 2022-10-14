#define _GLIBCXX_DEBUG

#include <bits/stdc++.h>

#define pb push_back
// #define int long long
#define all(x) x.begin(), x.end()
#define rall(x) x.rbegin(), x.rend()
#define ld long double
using namespace std;
const int M = 1000000007;
const int N = (1 << 23);
int F[N];

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int n;
    cin >> n;
    vector<int> A(n);
    for (int i = 0; i < n; i++) cin >> A[i];
    for (auto x : A) {
        F[x] = x;
    }
    for (int mask = 0; mask < (1 << 23); mask++) {
        for (int i = 0; i < 23; i++) {
            if ((mask >> i) & 1) {
                F[mask] = max(F[mask], F[mask ^ (1 << i)]);
            }
        }
    }
    for (auto x : A) {
        int y = N - 1 - x;
        if (F[y] == 0) {
            cout << "-1 ";
        } else {
            cout << F[y] << ' ';
        }
    }
    cout << '\n';
}