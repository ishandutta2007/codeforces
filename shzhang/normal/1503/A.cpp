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
char ans1[200005], ans2[200005];

void work()
{
    int n; scanf("%d", &n);
    scanf("%s", s + 1);
    if (s[1] != '1' || s[n] != '1') {
        printf("NO\n"); return;
    }
    int one_cnt = 0;
    for (int i = 1; i <= n; i++) {
        if (s[i] == '1') one_cnt++;
    }
    if (one_cnt % 2) {
        printf("NO\n"); return;
    }
    printf("YES\n");
    int one_idx = 1; bool cur = false;
    for (int i = 1; i <= n; i++) {
        if (s[i] == '1') {
            if (one_idx <= one_cnt / 2) {
                ans1[i] = ans2[i] = '(';
            } else {
                ans1[i] = ans2[i] = ')';
            }
            one_idx++;
        } else {
            if (cur) {
                ans1[i] = '('; ans2[i] = ')';
            } else {
                ans2[i] = '('; ans1[i] = ')';
            }
            cur = !cur;
        }
    }
    ans1[n + 1] = ans2[n + 1] = '\0';
    printf("%s\n%s\n", ans1 + 1, ans2 + 1);
}

int main()
{
    int t; scanf("%d", &t);
    for (int i = 1; i <= t; i++) work();
    return 0;
}