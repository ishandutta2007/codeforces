#include <iostream>
#include <cstring>
#include <algorithm>
#include <vector>
#include <string>
#include <set>

using namespace std;

const int maxN = 510000;
const int maxD = 60;
const int P = 1000000007;

int x[maxD], y[maxD], z[maxD];

void solve() {
    int n;
    scanf("%d", &n);

    vector < long long > a(n);
    for (int i = 0; i < n; ++i) {
        scanf("%lld", &a[i]);
    }

    for (int i = 0; i < 60; ++i) {
        long long s = 0, t = (1LL << i);
        for (int j = 0; j < n; ++j) {
            s += (t & a[j]);
            s %= (long long)(P);
        }
        x[i] = s;

        long long sy = 0, sz = 0;
        for (int j = 0; j < n; ++j) {
            if ((a[j] & t) == 0) {
                sy += t;
                sy %= (long long)(P);
            } else {
                sz += t;
                sz %= (long long)(P);
            }
        }
        y[i] = sy;
        z[i] = sz;
    }

    long long res = 0;
    for (int i = 0; i < n; ++i) {
        long long A = 0, B = 0;
        for (int j = 0; j < 60; ++j) {
            if (a[i] & (1LL << j)) {
                A += x[j];
                B += y[j];
                B += z[j];
            } else {
                B += z[j];
            }
        }
        A %= P;
        B %= P;

        /*long long cA = 0, cB = 0;
        for (int j = 0; j < n; ++j) {
            cA += (a[i] & a[j]);
            cB += (a[i] | a[j]);
        }*/
        res += (A * B);
        res %= P;
    }
    printf("%d\n", (int)(res));
}

int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);

    int t;
    scanf("%d", &t);
    for (int i = 0; i < t; ++i) {
        solve();
    }


    return 0;
}