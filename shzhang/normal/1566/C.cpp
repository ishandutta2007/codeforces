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

char s[100005], t[100005];
int f[100005];

void work()
{
    int n;
    scanf("%d%s%s", &n, s + 1, t + 1);
    int lastzero = 0, lastone = 0;
    for (int i = 1; i <= n; i++) {
        if (s[i] != t[i]) {
            f[i] = f[i-1] + 2;
            lastzero = lastone = i;
        } else if (s[i] == '0') {
            f[i] = f[i-1] + 1;
            if (lastone) f[i] = max(f[i], f[lastone - 1] + 2);
            lastzero = i;
        } else {
            f[i] = f[i-1];
            if (lastzero) f[i] = max(f[i], f[lastzero - 1] + 2);
            lastone = i;
        }
    }
    printf("%d\n", f[n]);
}

int main()
{
    int T; scanf("%d", &T);
    for (int i = 1; i <= T; i++) work();
    return 0;
}