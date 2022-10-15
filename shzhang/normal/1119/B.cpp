#include <cstdio>
#include <algorithm>
#include <vector>
#include <cstring>
#include <cmath>
#include <set>
#include <iostream>

using namespace std;

int a[1005];
int vals[1005];
int n, h;

bool check(int cnt)
{
    for (int i = 1; i <= cnt; i++) vals[i] = a[i];
    sort(vals + 1, vals + cnt + 1);
    long long ans = 0;
    for (int i = cnt; i >= 1; i -= 2) {
        if (i != 1) {
            ans += (long long)max(vals[i], vals[i-1]);
        } else {
            ans += (long long)vals[i];
        }
    }
    return ans <= h;
}

int main()
{
    scanf("%d%d", &n, &h);
    for (int i = 1; i <= n; i++) scanf("%d", a + i);
    int l = 1, r = n;
    while (l < r) {
        int mid = (l + r) / 2 + 1;
        if (check(mid)) {
            l = mid;
        } else {
            r = mid - 1;
        }
    }
    printf("%d", l);
    return 0;
}