#include <iostream>
#include <algorithm>
#include <vector>
#include <cstdlib>
#include <cstring>
#include <cassert>
#include <map>
#include <set>
#include <cstdio>

using namespace std;

const int MAXN = 5100;
const int MAXK = 15000000;

bool used[MAXK];
int a[MAXN];
int n, k, q;

void
upd(int &ans, int val)
{
    if (ans == -1 || ans > val) {
        ans = val;
    }
}

int
main()
{
    scanf("%d%d", &n, &k);
    for (int i = 0; i < n; ++i) {
        scanf("%d", &a[i]);
        used[a[i]] = true;
    }
    scanf("%d", &q);
    for (int i = 0; i < q; ++i) {
        int x;
        int res = -1;
        scanf("%d", &x);
        for (int p1 = 0; p1 < n; ++p1) {
            if (x % a[p1] == 0 && x / a[p1] <= k) {
                upd(res, x / a[p1]);
            }
            for (int i1 = 1; i1 <= k && a[p1] * i1 <= x; ++i1) {
                int rest = x - a[p1] * i1;
                for (int i2 = 1; i2 + i1 <= k; ++i2) {
                    if (rest % i2 == 0 && rest < MAXK * i2 && used[rest / i2]) {
                        upd(res, i1 + i2);
                    }
                }
            }
        }
        printf("%d\n", res);
    }
    return 0;
}