#include <cstdio>
#include <algorithm>
#include <vector>
#include <set>
#include <cstdlib>
#include <utility>
#include <cmath>
#include <queue>
#include <stack>
#include <cstring>

using namespace std;

#define ll long long

#ifndef ONLINE_JUDGE
#define debug(format, ...) fprintf(stderr, \
    "%s:%d: " format "\n", __func__, __LINE__,##__VA_ARGS__)
#else
#define debug(format, ...)
#define NDEBUG
#endif

char s[15];

void work()
{
    scanf("%s", s);
    int ans = 100;
    for (int i = 0; i < (1 << 10); i++) {
        bool good = true;
        for (int j = 0; j < 10; j++) {
            bool bit = (i & (1 << j));
            if (bit && s[j] == '0') good = false;
            if (!bit && s[j] == '1') good = false;
        }
        if (!good) continue;
        int a_cnt = 0, b_cnt = 0;
        int num = 10;
        for (int j = 0; j < 10; j++) {
            bool bit = (i & (1 << j));
            if (bit) {
                if (j % 2) b_cnt++;
                else a_cnt++;
            }
            int besta = a_cnt, bestb = b_cnt;
            for (int k = j + 1; k < 10; k++) {
                if (k % 2) bestb++;
                else besta++;
            }
            if (besta < b_cnt || bestb < a_cnt) {
                num = j + 1; break;
            }
        }
        ans = min(ans, num);
    }
    printf("%d\n", ans);
}

int main()
{
    int t; scanf("%d", &t);
    for (int i = 1; i <= t; i++) work();
    return 0;
}