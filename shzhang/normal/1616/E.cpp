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

#define lowbit(x) ((x)&(-(x)))

int n;

int rquery(int* arr, int v)
{
    int ans = 0;
    while (v) {
        ans += arr[v]; v -= lowbit(v);
    }
    return ans;
}

void modify(int* arr, int loc, int val)
{
    //printf("%d %lld\n", loc, val);
    while (loc <= n) {
        arr[loc] += val; loc += lowbit(loc);
    }
}

int query(int* arr, int l, int r)
{
    return rquery(arr, r) - rquery(arr, l-1);
}

char s[100005];
char t[100005];

vector<int> que[26];
int use[100005];

void work()
{
    scanf("%d", &n);
    scanf("%s", s + 1);
    scanf("%s", t + 1);
    for (int i = n; i >= 1; i--) {
        que[s[i] - 'a'].push_back(i);
    }
    ll ans = 1000000000000000000LL;
    ll curans = 0;
    for (int i = 1; i <= n; i++) {
        bool found = false;
        int minpos = n + 1;
        for (int j = 0; j < (t[i] - 'a'); j++) {
            if (!que[j].empty()) {
                minpos = min(minpos, que[j].back());
                found = true;
            }
        }
        if (found) {
            ans = min(ans, curans + (ll)(minpos - 1 - rquery(use, minpos)));
        }
        if (!que[t[i] - 'a'].empty()) {
            int pos = que[t[i] - 'a'].back();
            que[t[i] - 'a'].pop_back();
            curans += (ll)(pos - 1 - rquery(use, pos));
            modify(use, pos, 1);
        } else {
            break;
        }
        //printf("after round %d: %lld %lld\n", i, curans, ans);
    }
    if (ans == 1000000000000000000LL) {
        printf("-1\n");
    } else {
        printf("%lld\n", ans);
    }
    for (int i = 0; i < 26; i++) que[i].clear();
    for (int i = 1; i <= n; i++) use[i] = 0;
}

int main()
{
    int q; scanf("%d", &q);
    for (int i = 1; i <= q; i++) work();
    return 0;
}