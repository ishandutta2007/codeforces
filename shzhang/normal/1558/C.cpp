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

int a[2500], pos[2500], n;

vector<int> ans;

void flip(int x)
{
    int l = 1, r = x;
    while (l < r) {
        swap(a[l], a[r]);
        pos[a[l]] = l;
        pos[a[r]] = r;
        l++; r--;
    }
    ans.push_back(x);
}

void work()
{
    scanf("%d", &n); ans.clear();
    for (int i = 1; i <= n; i++) {
        scanf("%d", a + i);
        pos[a[i]] = i;
    }
    for (int i = 1; i <= n; i++) {
        if (i % 2 != a[i] % 2) {
            printf("-1\n"); return;
        }
    }
    for (int i = 1; i < n; i += 2) {
        int ipos = pos[i];
        int npos = pos[i+1];
        int xpos;
        //printf("! %d %d\n", ipos, npos);
        if (ipos < npos) {
            xpos = npos - 1;
        } else {
            xpos = ipos - npos;
        }
        flip(ipos); flip(pos[i+1] - 1);
        flip(xpos + 2);
        flip(3);
        flip(n - i + 1);
    }
    flip(n);
    printf("%d\n", (int)ans.size());
    for (int i = 0; i < ans.size(); i++) {
        printf("%d ", ans[i]);
    }
    printf("\n");
    /*for (int i = 1; i <= n; i++) {
        printf("%d ", a[i]);
    }
    printf("\n");*/
}

int main()
{
    int t; scanf("%d", &t);
    for (int i = 1; i <= t; i++) work();
    return 0;
}