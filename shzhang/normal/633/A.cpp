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
    int a, b, c;
    scanf("%d%d%d", &a, &b, &c);
    for (int x = 0; x <= c; x += a) {
        if ((c - x) % b == 0) {
            printf("Yes"); return 0;
        }
    }
    printf("No");
    return 0;
}