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

int a[200005];
vector<int> ans;

int n;

void do_op(int p)
{
    ans.push_back(p);
    a[p+1] = a[p-1];
    a[p] = a[p+2];
}

void swork(int mval)
{
    vector<int> pos;
    queue<int> que;
    for (int i = 0; i <= n; i++) {
        if (i % 2 == mval) {
            pos.push_back(i);
            if (!a[i]) que.push((int)pos.size() - 1);
        }
    }
    while (!que.empty()) {
        int cur = que.front(); que.pop();
        //printf("process %d\n", pos[cur]);
        if (cur > 0 && a[pos[cur-1]]) {
            do_op(pos[cur] - 2);
            que.push(cur-1);
        }
        if (cur < (int)pos.size() - 1 && a[pos[cur+1]]) {
            do_op(pos[cur] + 1);
            que.push(cur+1);
        }
    }
    //printf("! %d\n", (int)ans.size());
}

void work()
{
    ans.clear();
    scanf("%d", &n);
    bool odd_on = true;
    for (int i = 1; i <= n; i++) {
        scanf("%d", a + i);
        a[i] += a[i-1];
        a[i] %= 2;
        if (i % 2 == 1 && !a[i]) odd_on = false;
    }
    if (a[n] || ((n % 2 == 0) && odd_on)) {
        printf("NO\n"); return;
    }
    swork((n + 1) % 2);
    swork(n % 2);
    printf("YES\n%d\n", (int)ans.size());
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