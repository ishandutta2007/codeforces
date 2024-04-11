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

vector<pair<int, int> > ans;

void work(int off, int siz)
{
    if (siz == 1) return;
    work(off, siz / 2);
    work(off + siz / 2, siz / 2);
    for (int i = off; i < off + siz / 2; i++) {
        ans.push_back(make_pair(i, i + siz / 2));
    }
}

int main()
{
    int n; scanf("%d", &n);
    int x = 1;
    while (x <= n) x *= 2;
    x /= 2;
    work(1, x);
    work(n - x + 1, x);
    printf("%d\n", (int)ans.size());
    for (int i = 0; i < ans.size(); i++) {
        printf("%d %d\n", ans[i].first, ans[i].second);
    }
    return 0;
}