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

int w[105];

void work()
{
    int n, x; scanf("%d%d", &n, &x);
    int s = 0;
    vector<int> vec;
    for (int i = 1; i <= n; i++) {
        scanf("%d", w + i); s += w[i];
        vec.push_back(w[i]);
    }
    if (s == x) {
        printf("NO\n"); return;
    }
    printf("YES\n");
    int cur = 0;
    for (int i = 1; i <= n; i++) {
        if (cur + vec.back() == x) {
            int val = vec.back();
            vec.pop_back();
            printf("%d ", vec.back());
            cur += vec.back();
            vec.pop_back();
            vec.push_back(val);
        } else {
            printf("%d ", vec.back());
            cur += vec.back();
            vec.pop_back();
        }
    }
    printf("\n");
}

int main()
{
    int t; scanf("%d", &t);
    for (int i = 1; i <= t; i++) work();
    return 0;
}