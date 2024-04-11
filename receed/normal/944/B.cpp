#include <iostream>
#include <cstdio>
#include <vector>
#include <algorithm>
#include <string>
#include <set>
#include <map>
#include <unordered_set>
#include <unordered_map>
#include <cstring>
#include <cmath>
#include <numeric>
#include <deque>
#include <queue>
typedef long long l;
typedef long double ld;
using namespace std;


int main() {
#ifndef ONLINE_JUDGE
	freopen("input.in", "r", stdin);
	freopen("output.out", "w", stdout);
#endif
	int n, mn = 1e6;
    scanf("%d", &n);
    vector<int> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
        mn = min(mn, a[i]);
    }
    vector<int> cnt(3);
    for (int i = 0; i < n; i++)
        cnt[a[i] - mn]++;
    if (cnt[2] == 0) {
        printf("%d\n", n);
        for (int i : a)
            printf("%d ", i);
        printf("\n");
        return 0;
    }
    int r1 = min(cnt[0], cnt[2]), r2 = cnt[1] / 2;
    printf("%d\n", n - max(r1, r2) * 2);
    if (r1 > r2) {
        cnt[0] -= r1;
        cnt[1] += r1 * 2;
        cnt[2] -= r1;
    }
    else {
        cnt[0] += r2;
        cnt[1] -= r2 * 2;
        cnt[2] += r2;
    }
    for (int i = 0; i < 3; i++)
        for (int j = 0; j < cnt[i]; j++)
            printf("%d ", mn + i);
}