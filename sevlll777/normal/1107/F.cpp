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
int T[600][600], u[600], v[600], p[600], way[600];

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int n;
    cin >> n;
    vector<int> A(n), B(n), K(n);
    for (int i = 0; i < n; i++) cin >> A[i] >> B[i] >> K[i];
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            T[i+1][j+1] = -(A[j] - B[j] * min(i, K[j]));
        }
    }
    int res = 0;
    for (int i = 1; i <= n; i++) {
        p[0] = i;
        int cf = 0;
        vector<int> min_value(n + 1, 1e14);
        vector<bool> used(n + 1, false);

        used[cf] = true;
        int ic = p[cf], j2;
        int heh = 1e9;
        for (int j = 1; j <= n; j++) {
            if (!used[j]) {
                int value = T[ic][j] - u[ic] - v[j];
                if (value < min_value[j]) {
                    min_value[j] = value;
                    way[j] = cf;
                }
                if (min_value[j] < heh) {
                    heh = min_value[j];
                    j2 = j;
                }
            }
        }
        for (int j = 0; j <= n; j++) {
            if (used[j]) {
                u[p[j]] += heh;
                v[j] -= heh;
            } else {
                min_value[j] -= heh;
            }
        }
        cf = j2;
        while (p[cf]) {
            used[cf] = true;
            int ic = p[cf], j2;
            int heh = 1e14;
            for (int j = 1; j <= n; j++) {
                if (!used[j]) {
                    int value = T[ic][j] - u[ic] - v[j];
                    if (value < min_value[j]) {
                        min_value[j] = value;
                        way[j] = cf;
                    }
                    if (min_value[j] < heh) {
                        heh = min_value[j];
                        j2 = j;
                    }
                }
            }
            for (int j = 0; j <= n; j++) {
                if (used[j]) {
                    u[p[j]] += heh;
                    v[j] -= heh;
                } else {
                    min_value[j] -= heh;
                }
            }
            cf = j2;
        }

        int g = way[cf];
        p[cf] = p[g];
        cf = g;
        while (cf) {
            int g = way[cf];
            p[cf] = p[g];
            cf = g;
        }

        res = max(res, v[0]);
    }

    cout << res << '\n';

}