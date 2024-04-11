#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <vector>

using namespace std;

#define maxn 2014

int ans[maxn];
int n, m, k;

bool
input_data()
{
    memset(ans, 0, sizeof(ans));
    if (scanf("%d%d%d", &n, &m, &k) != 3) {
        return false;
    }
    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= m; ++j) {
            char c = 0;
            scanf(" %c", &c);
            if (c == 'R') {
                int nxt = j + i - 1;
                if (nxt <= m) {
                    ans[nxt]++;
                }
            } else if (c == 'L') {
                int nxt = j - i + 1;
                if (nxt > 0) {
                    ans[nxt]++;
                }
            } else if (c == 'U') {
                if (i % 2 == 1) {
                    ans[j]++;
                }
            }
        }
    }
    for (int i = 1; i <= m; ++i) {
        printf("%d ", ans[i]);
    }
    printf("\n");
    return true;
}

int
main()
{
#ifndef _DEBUG
    input_data();
#else
    while (input_data()) {}
#endif
    return 0;
}