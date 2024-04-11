#include <iostream>
#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <vector>
#include <algorithm>

using namespace std;

const int MAXN = 1005000;

char s[MAXN];
int z[MAXN];
int add[MAXN];
int n, k;

int
main()
{
    scanf("%d%d %s", &n, &k, s);
    int l = 0, r = -1;
    z[0] = 0;
    for (int i = 1; i < n; ++i) {
        int len = 0;
        if (i <= r) {
            len = min(r - i + 1, z[i - l]);
        }
        while (len + i < n && s[len + i] == s[len]) ++len;
        z[i] = len;
        if (len != 0 && i + len - 1 > r) {
            l = i, r = i + len - 1;
        }
    }
    for (int i = 0; i <= n; ++i) {
        add[i] = 0;
    }
    for (int cyclen = 1; cyclen * k <= n; ++cyclen) {
        if (z[cyclen] < cyclen * (k - 1)) {
            continue;
        }
        int from = cyclen * k - 1, to = min(from + cyclen + 1, cyclen + z[cyclen]);
        add[from]++;
        add[to]--;
    }
    int cursum = 0;
    for (int i = 0; i < n; ++i) {
        cursum += add[i];
        if (cursum) {
            putchar('1');
        } else {
            putchar('0');
        }
    }
    puts("");
    return 0;
}