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
#define ld long double
using namespace std;

int n, k;
int T[60][60], u[60], v[60], p[60], way[60];


signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    cin >> n >> k;
    string a, b;
    cin >> a >> b;
    for (int i = 0; i < n; i++) {
        int aa, bb;
        if (a[i] < 'a') {
            aa = 26 + a[i] - 'A' + 1;
        } else {
            aa = a[i] - 'a' + 1;
        }
        if (b[i] < 'a') {
            bb = 26 + b[i] - 'A' + 1;
        } else {
            bb = b[i] - 'a' + 1;
        }
        T[aa][bb]--;
    }
    int res = 0;
    for (int i = 1; i <= k; i++) {
        p[0] = i;
        int cf = 0;
        vector<int> min_value(k + 1, 1e9);
        vector<bool> used(k + 1, false);

        used[cf] = true;
        int ic = p[cf], j2;
        int heh = 1e9;
        for (int j = 1; j <= k; j++) {
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
        for (int j = 0; j <= k; j++) {
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
            int heh = 1e9;
            for (int j = 1; j <= k; j++) {
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
            for (int j = 0; j <= k; j++) {
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

    vector<int> ans(k + 1);
    for (int i = 1; i <= k; i++) ans[p[i]] = i;
    cout << res << '\n';
    for (int i = 1; i <= k; i++) {
        if (ans[i] <= 26) {
            cout << (char) ('a' - 1 + ans[i]);
        } else {
            cout << (char) ('A' + 5 + ans[i] - 32);
        }
    }


}