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
    int n; scanf("%d", &n);
    scanf("%s", s + 1);
    if (n == 1) {
        printf("%c%c\n", s[1], s[1]); return;
    }
    if (s[1] == s[2]) {
        printf("%c%c\n", s[1], s[2]); return;
    }
    int k = 1;
    while (k < n && s[k] >= s[k+1]) k++;
    for (int i = 1; i <= k; i++) printf("%c", s[i]);
    for (int i = k; i >= 1; i--) printf("%c", s[i]);
    printf("\n");
}

int main()
{
    int t; scanf("%d", &t);
    for (int i = 1; i <= t; i++) work();
    return 0;
}