#include <cstdio>
#include <memory.h>
#include <iostream>
#include <vector>
#include <string>

using namespace std;

int f[51][1515];

int main() {
    int n, s, k;
    scanf("%d %d %d", &n, &s, &k);
    s--;
    vector<int> a(n);
    for (int i = 0; i < n; i++) scanf("%d", &a[i]);
    string c;
    cin >> c;

    memset(f, 0xff, sizeof(f));
    for (int i = 0; i < n; i++)
        f[i][abs(i - s)] = a[i];

    for (int t = 0; t < 1414; t++) {
        for (int i = 0; i < n; i++)
            if (f[i][t] > 0) {
                if (f[i][t] >= k) {
                    printf("%d\n", t);
                    return 0;
                }
                for (int j = 0; j < n; j++)
                    if (c[i] != c[j] && a[j] > a[i]) {
                        f[j][t + abs(i - j)] = max(f[j][t + abs(i - j)], f[i][t] + a[j]);
                    }
            }
    }

    printf("-1\n");

    return 0;
}