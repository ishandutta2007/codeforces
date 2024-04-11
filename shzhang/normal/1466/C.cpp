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

int t;

char s[100005];

void work()
{
    int ans = 0;
    scanf("%s", s + 1);
    int n = strlen(s + 1);
    for (int i = 2; i <= n; i++) {
        if (s[i] == s[i-1] || s[i] == s[i-2]) {
            ans++;
            for (int j = 0; j < 26; j++) {
                bool good = true;
                for (int k = -2; k <= 2; k++) {
                    if (k != 0 && i + k >= 1 && i + k <= n && s[i+k] == 'a' + j) {
                        good = false; break;
                    }
                }
                if (good) {
                    s[i] = 'a' + j; break;
                }
            }
        }
    }
    printf("%d\n", ans);
}

int main()
{
    scanf("%d", &t);
    for (int i = 1; i <= t; i++) {
        work();
    }
    return 0;
}