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
int a[1005];
int cnt[1005];

int getmex(void)
{
    for (int i = 0; i <= n + 3; i++) cnt[i] = 0;
    for (int i = 1; i <= n; i++) cnt[a[i]]++;
    for (int i = 0; i <= n + 3; i++) {
        if (!cnt[i]) return i;
    }
    return 0;
}

vector<int> ans;

void op(int pos)
{
    ans.push_back(pos);
    a[pos] = getmex();
}

bool fixed[1005];

void work(void)
{
    ans.clear();
    scanf("%d", &n);
    for (int i = 1; i <= n; i++) {
        scanf("%d", a + i); fixed[i] = false;
    }
    int remaining = n;
    while (remaining) {
        int mexv = getmex();
        if (mexv == n) {
            for (int i = 1; i <= n; i++) {
                if (!fixed[i]) {
                    op(i); break;
                }
            }
        } else {
            op(mexv + 1); fixed[mexv + 1] = true; remaining--;
        }
    }
    printf("%d\n", (int)ans.size());
    for (int i = 0; i < ans.size(); i++) {
        printf("%d ", ans[i]);
    }
    printf("\n");
}

int main()
{
    int t; scanf("%d", &t);
    for (int i = 1; i <= t; i++) work();
    return 0;
}