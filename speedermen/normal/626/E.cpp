#pragma GCC optimization ("unroll-loops")
#pragma GCC optimize("Ofast")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4")

#include <bits/stdc++.h>

using namespace std;

int main() {
//    freopen("input.txt", "r", stdin);
    int n;
    scanf("%d", &n);
    vector <int> x(n + 1);
    for (int i = 1; i <= n; ++i) {
        scanf("%d", &x[i]);
    }
    sort(x.begin() + 1, x.end());
    vector <long long> sx(n + 1, 0LL);
    for (int i = 1; i <= n; ++i) {
        sx[i] = sx[i - 1] + x[i];
    }
    long long ans = 0;
    pair <int, int> where = make_pair(1, 0);
    for (int i = 1; i <= n; ++i) {
        int l = 1, r = min(i - 1, n - i);
        while (r - l > 2) {
            int dl = l + (r - l) / 3, dr = r - (r - l) / 3;
            long long fdl = sx[i - 1] - sx[i - 1 - dl] + sx[n] - sx[n - dl] - 2LL * dl * x[i];
            long long fdr = sx[i - 1] - sx[i - 1 - dr] + sx[n] - sx[n - dr] - 2LL * dr * x[i];
            if (fdl * (2 * dr + 1) > fdr * (2 * dl + 1)) {
                r = dr;
            } else {
                l = dl;
            }
        }
        for (int k = l; k <= r; ++k) {
            if (ans * (2 * k + 1) < (sx[i - 1] - sx[i - 1 - k] + sx[n] - sx[n - k] - 2LL * k * x[i]) * (2 * where.second + 1)) {
                ans = (sx[i - 1] - sx[i - 1 - k] + sx[n] - sx[n - k] - 2LL * k * x[i]);
                where = make_pair(i, k);
            }
        }
    }
    vector <int> result;
    for (int i = where.first - where.second; i <= where.first; ++i) {
        result.push_back(x[i]);
    }
    for (int i = n - where.second + 1; i <= n; ++i) {
        result.push_back(x[i]);
    }
    printf("%d\n", (int)result.size());
    for (int i = 0; i < (int)result.size(); ++i) {
        printf("%d%c", result[i], i == (int)result.size() - 1 ? '\n' : ' ');
    }
    return 0;
}