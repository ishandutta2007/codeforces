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

char s[100010];
int scnt[100010];

int main()
{
    int n, q; scanf("%d%d", &n, &q);
    scanf("%s", s + 1);
    int ans = 0;
    for (int i = 1; i + 2 <= n; i++) {
        if (s[i] == 'a' && s[i+1] == 'b' && s[i+2] == 'c') {
            scnt[i] = 1;
            ans++;
        }
    }
    for (int qr = 1; qr <= q; qr++) {
        int pos; char c[5];
        scanf("%d%s", &pos, c);
        s[pos] = c[0];
        for (int i = max(pos - 2, 0); i <= min(pos, n - 2); i++) {
            int new_cnt = (s[i] == 'a' && s[i+1] == 'b' && s[i+2] == 'c' ? 1 : 0);
            ans += new_cnt - scnt[i];
            scnt[i] = new_cnt;
        }
        printf("%d\n", ans);
    }
    return 0;
}