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

bool required[1000005];
int freq[1000005];
int psum[1000005];

void work()
{
    int n, c; scanf("%d%d", &n, &c);
    for (int i = 1; i <= c; i++) {
        required[i] = false;
        freq[i] = psum[i] = 0;
    }
    for (int i = 1; i <= n; i++) {
        int x; scanf("%d", &x);
        freq[x]++;
    }
    for (int i = 1; i <= c; i++) {
        psum[i] = psum[i-1] + freq[i];
    }
    for (int i = 1; i <= c; i++) {
        if (!freq[i]) continue;
        for (int mult = 1; i * mult <= c; mult++) {
            int cnt = ((mult + 1) * i - 1 > c ? psum[c] :
                psum[(mult + 1) * i - 1]) - psum[mult * i - 1];
            //printf("%d [%d %d]: %d\n", i, mult * i, (mult + 1) * i - 1,
            //    cnt);
            if (cnt) required[mult] = true;
        }
    }
    for (int i = 1; i <= c; i++) {
        if (required[i] && !freq[i]) {
            printf("No\n"); return;
        }
    }
    printf("Yes\n");
}

int main()
{
    int t; scanf("%d", &t);
    for (int i = 1; i <= t; i++) work();
    return 0;
}