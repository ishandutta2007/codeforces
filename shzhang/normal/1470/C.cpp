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

int query(int x)
{
    printf("? %d\n", x);
    fflush(stdout);
    int ans; scanf("%d", &ans);
    return ans;
}

bool samesign(int x, int y)
{
    return (ll)x * (ll)y > 0;
}

int main()
{
    int n, k; scanf("%d%d", &n, &k);
    int s = (int)sqrt((double)n);
    //printf("%d\n", s);
    if (n <= 10) s = 1;
    for (int i = 1; i <= s; i++) query(1);
    vector<pair<int, int> > prs;
    for (int i = 1; i <= n; i += s) {
        prs.push_back(make_pair(i, query(i)));
    }
    int x = -1;
    for (int i = 0; i < prs.size(); i++) {
        if (prs[i].second != k) {
            x = i; break;
        }
    }
    int delta = (prs[x].second < k ? 1 : -1);
    while (true) {
        int nxt = x + delta;
        nxt %= prs.size();
        nxt += prs.size();
        nxt %= prs.size();
        if (samesign(prs[nxt].second - k, prs[x].second - k)) {
            x = nxt;
        } else {
            break;
        }
    }
    int pos = prs[x].first;
    while (query(pos) != k) {
        pos += delta;
        if (pos <= 0) pos += n;
        if (pos > n) pos -= n;
    }
    printf("! %d\n", pos);
    return 0;
}