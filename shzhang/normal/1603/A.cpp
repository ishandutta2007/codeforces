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

int n;
int a[100005];

void work()
{
    scanf("%d", &n);
    for (int i = 1; i <= n; i++) {
        scanf("%d", a + i);
    }
    bool good = true;
    for (int i = 1; i <= min(n, 200); i++) {
        bool found = false;
        for (int j = 2; j <= i + 1; j++) {
            if (a[i] % j != 0) found = true;
        }
        if (!found) good = false;
    }
    printf("%s\n", good ? "YES" : "NO");
}

int main()
{
    int t; scanf("%d", &t);
    for (int i = 1; i <= t; i++) work();
    return 0;
}