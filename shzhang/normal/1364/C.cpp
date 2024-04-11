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

int a[100005];
bool used[100005];

int main()
{
    int n;
    scanf("%d", &n);
    for (int i = 1; i <= n; i++) {
        scanf("%d", a + i);
        used[a[i]] = true;
    }
    int nxtv = 0;
    for (int i = 1; i <= n; i++) {
        if (a[i] > a[i-1]) {
            printf("%d ", a[i - 1]);
            used[a[i-1]] = true;
        } else {
            while (used[nxtv]) nxtv++;
            printf("%d ", nxtv); nxtv++;
        }
    }
    return 0;
}