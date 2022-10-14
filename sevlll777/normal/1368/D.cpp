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
#define ld long double
using namespace std;


signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int n;
    cin >> n;
    vector<int> A(n);
    int s = 0;
    for (int i = 0; i < n; i++) {
        cin >> A[i];
        s += A[i];
    }
    int gg = 0;
    for (int b = 0; b < 20; b++) {
        bool ok = true;
        for (auto x : A) {
            if ((x >> b) % 2 == 0) {
                ok = false;
                break;
            }
        }
        if (ok) {
            gg += (1 << b);
        }
    }
    int ans = 0;
    for (int i = 0; i < n; i++) {
        A[i] -= gg;
    }

    vector<int> B(n);
    for (int b = 0; b < 20; b++) {
        int p2b = (1 << b);
        int cnt = 0;
        for (int i = 0; i < n; i++) {
            if ((A[i] >> b) % 2 == 1) cnt++;
        }
        for (int i = 0; i < cnt; i++) B[i] += p2b;
    }

    for (auto num : B) ans += (gg + num) * (gg + num);

    cout << ans << '\n';

}