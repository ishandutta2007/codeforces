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

char s[100005];

void work()
{
    scanf("%s", s + 1);
    int n = strlen(s + 1);
    int zeros = 0, ones = 0;
    int minzero = n + 1, maxzero = 0;
    for (int i = 1; i <= n; i++) {
        if (s[i] == '0') {
            zeros++;
            minzero = min(minzero, i);
            maxzero = max(maxzero, i);
        } else {
            ones++;
        }
    }
    if (zeros == 0) {
        printf("0\n");
    } else if (maxzero - minzero + 1 == zeros) {
        printf("1\n");
    } else {
        printf("2\n");
    }
}

int main()
{
    int t; scanf("%d", &t);
    for (int i = 1; i <= t; i++) work();
    return 0;
}