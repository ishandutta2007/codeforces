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
    set<int> squares;
    for (int i = 1; i <= 40000; i++) {
        squares.insert(i * i);
    }
    for (int i = 1; i <= t; i++) {
        int n; scanf("%d", &n);
        if (n % 2 == 0 && squares.count(n / 2)) {
            printf("YES\n");
        } else if (n % 4 == 0 && squares.count(n / 4)) {
            printf("YES\n");
        } else {
            printf("NO\n");
        }
    }
    return 0;
}