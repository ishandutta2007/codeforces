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

#define int long long
#define pb push_back
using namespace std;

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<int> A(n), B(n);
        for (int i = 0; i < n; i++) cin >> A[i];
        for (int i = 0; i < n; i++) cin >> B[i];
        int mina = 1e10, minb = 1e10;
        for (auto a : A) mina = min(a, mina);
        for (auto b : B) minb = min(b, minb);
        int ans = 0;
        for (int i = 0; i < n; i++) {
            ans += max(A[i] - mina, B[i] - minb);
        }
        cout << ans << '\n';
    }
}