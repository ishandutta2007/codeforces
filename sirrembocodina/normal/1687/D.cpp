#pragma GCC target ("avx2")
#pragma GCC optimization ("O3")
#pragma GCC optimization ("unroll-loops")
#include <ext/pb_ds/assoc_container.hpp>
using namespace __gnu_pbds;
#include <bits/stdc++.h>

using namespace std;

#define int int64_t
#define forn(i, n) for (int i = 0; i < (int)(n); i++)

struct my_hash {
    inline size_t operator()(const pair<int, int>& a) const {
        return a.first * 31 + a.second;
    }
};

int32_t LB[int(2e6) + 1];
int n;

inline int lb(int x) {
    if (x > 2e6) {
        return n;
    } else if (x < 0) {
        return 0;
    } else {
        return LB[x];
    }
}

int32_t main() {
    srand(time(nullptr));
    ios_base::sync_with_stdio(0);
    cin >> n;
    vector<int> x(n);
    for (int i = 0; i < n; i++) {
        cin >> x[i];
    }
    for (int i = 0; i < 2e6; i++) {
        LB[i] = -1;
    }
    LB[int(2e6)] = n;
    for (int i = n - 1; i >= 0; i--) {
        LB[x[i]] = i;
    }
    for (int i = 2e6 - 1; i >= 0; i--) {
        if (LB[i] == -1) {
            LB[i] = LB[i + 1];
        }
    }
    for (int a = 1; ; a++) {
        int L = max(x[0], a * a), R = a * a + a + 1;
        if (L >= R) {
            continue;
        }
        int last = -1;
        bool fail = false;
        for (int b = a; ; b++) {
            int l = lb(x[0] + b * b - R + 1);
            int r = lb(x[0] + b * b + b + 1 - L);
            if (l > last + 1) {
                fail = true;
                break;
            }
            if (l == r) {
                continue;
            }
            last = r - 1;
            L = max(L, b * b - x[l] + x[0]);
            R = min(R, b * b + b + 1 - x[r - 1] + x[0]);
            if (L >= R) {
                fail = true;
                break;
            }
            if (r == n) {
                break;
            }
        }
        if (fail) {
            continue;
        }
        cout << L - x[0];
        return 0;
    }
}