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
// #define int long long
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
        bitset<8009> kek;
        vector<int> A(n);
        for (int i = 0; i < n; i++) cin >> A[i];
        for (int l = 0; l < n; l++) {
            int s = A[l];
            for (int j = l + 1; j < n; j++) {
                s += A[j];
                if (s > n) break;
                kek[s] = true;
            }
        }
        int ans = 0;
        for (auto x : A) ans += kek[x];
        cout << ans << '\n';
    }

}