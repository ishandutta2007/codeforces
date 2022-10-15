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

int gcd(int a, int b)
{
    if (b == 0) return a;
    return gcd(b, a % b);
}

struct List {
    List* prev;
    List* nxt;
    int idx;
    int val;
};

int arr[100005];
List* lst[100005];

void work()
{
    int n; scanf("%d", &n);
    for (int i = 1; i <= n; i++) {
        scanf("%d", arr + i);
        lst[i] = new List;
    }
    for (int i = 1; i <= n; i++) {
        lst[i]->val = arr[i];
        lst[i]->prev = lst[i == 1 ? n : i-1];
        lst[i]->nxt = lst[i == n ? 1 : i+1];
        lst[i]->idx = i;
    }
    vector<int> ans;
    queue<int> que;
    for (int i = 2; i <= n; i++) {
        if (gcd(lst[i]->val, lst[i]->prev->val) == 1) {
            que.push(i);
        }
    }
    if (gcd(lst[1]->val, lst[1]->prev->val) == 1) {
        que.push(1);
    }
    while (!que.empty()) {
        int cur = que.front(); que.pop();
        ans.push_back(cur);
        if (lst[cur]->nxt == lst[cur]) break;
        lst[cur]->prev->nxt = lst[cur]->nxt;
        lst[cur]->nxt->prev = lst[cur]->prev;
        int nxtval = lst[cur]->nxt->idx;
        if (!que.empty() && que.front() == nxtval) que.pop();
        if (gcd(lst[cur]->nxt->val, lst[cur]->prev->val) == 1)
            que.push(nxtval);
    }
    printf("%d ", (int)ans.size());
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