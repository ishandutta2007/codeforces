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

int main()
{
    int t; scanf("%d", &t);
    for (int i = 1; i <= t; i++) {
        int n, s; scanf("%d%d", &n, &s);
        int cnt = n / 2 + 1;
        printf("%d\n", s / cnt);
    }
    return 0;
}