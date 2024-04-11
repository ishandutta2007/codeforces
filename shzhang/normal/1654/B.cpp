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

char s[200005];

void work()
{
    int last[26];
    scanf("%s", s + 1);
    int n = strlen(s + 1);
    for (int i = 0; i < 26; i++) last[i] = n + 1;
    for (int i = 1; i <= n; i++) {
        last[s[i] - 'a'] = i;
    }
    int minv = n + 1;
    for (int i = 0; i < 26; i++) minv = min(minv, last[i]);
    printf("%s\n", s + minv);
}

int main()
{
    int t; scanf("%d", &t);
    for (int i = 1; i <= t; i++) work();
    return 0;
}