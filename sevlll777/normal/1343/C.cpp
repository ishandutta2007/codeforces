// #define _GLIBCXX_DEBUG

#include <iostream>
#include <iomanip>
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
#include <random>
#include <queue>
#include <bitset>

#define int long long
#define dbl long double
#define pb push_back
#define str string
using namespace std;
const int M = 998244353;


signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<int> A(n);
        for (int i = 0; i < n; i++) cin >> A[i];
        vector<int> block;
        int neg = -1e9 - 1;
        int pos = 1e9 + 1;
        if (A[0] > 0) pos = A[0];
        if (A[0] < 0) neg = A[0];
        int ans = 0;
        for (int i = 1; i < n; i++) {
            if (A[i - 1] * A[i] < 0) {
                if (A[i - 1] < 0) ans += neg;
                if (A[i - 1] > 0) ans += pos;
                pos = 1e9 + 1;
                neg = -1e9 - 1;
                if (A[i] > 0) pos = A[i];
                if (A[i] < 0) neg = A[i];
            } else {
                if (A[i] > 0) pos = max(pos, A[i]);
                if (A[i] < 0) neg = max(neg, A[i]);
            }
        }
        if (pos != 1e9+1) ans += pos;
        if (neg != -1e9-1) ans += neg;
        cout << ans << '\n';

    }

}