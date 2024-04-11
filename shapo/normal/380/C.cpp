#include <iostream>
#include <cstdio>
#include <algorithm>
#include <vector>
#include <utility>
#include <cstring>
#include <cstdlib>
#include <stack>

using namespace std;

#define maxn 1000500
#define maxk 1048576

char s[maxn];
int n;
int q;
int ans[maxn];
int sum[2 * maxk];
int type[maxn];
int curk;

void
add(int x)
{
    x += curk - 1;
    while (x) {
        sum[x]++;
        x /= 2;
    }
}

int
getSum(int l, int r)
{
    int res = 0;
    l += curk - 1;
    r += curk - 1;
    while (l < r) {
        if (l % 2 == 1) {
            res += sum[l];
        }
        if (r % 2 == 0) {
            res += sum[r];
        }
        l = (l + 1) / 2;
        r = (r - 1) / 2;
    }
    if (l == r) res += sum[l];
    return res;
}

int
main(int argc, char **argv)
{
    gets(s);
    scanf("%d", &q);
    vector < pair < pair < int, int >, int > > query;
    for (int i = 0; i < q; ++i) {
        int l, r;
        scanf("%d%d", &l, &r);
        query.push_back(make_pair(make_pair(-l, r), i));
    }
    int n = strlen(s);
    curk = 2;
    while (curk < n) {
        curk *= 2;
    }
    for (int i = 0; i < 2 * curk; ++i) {
        sum[i] = 0;
    }
    for (int i = 1; i <= n; ++i) {
        type[i] = (s[i - 1] == '(') ? 1 : -1;
    }
    sort(query.begin(), query.end());
    stack < int > pos_close;
    int cpos = 0;
    for (int i = n; i >= 1; --i) {
        if (type[i] == -1) {
            pos_close.push(i);
        } else {
            int nxt = -1;
            if (!pos_close.empty()) {
                nxt = pos_close.top();
                pos_close.pop();
            }
            if (nxt != -1) {
                add(nxt);
            }
        }
        while (cpos < int(query.size()) && -(query[cpos].first.first) == i) {
            int l = -(query[cpos].first.first);
            int r = query[cpos].first.second;
            int res = getSum(l, r) * 2;
            ans[query[cpos].second] = res;
            ++cpos;
        }
    }
    for (int i = 0; i < q; ++i) {
        printf("%d\n", ans[i]);
    }
    return 0;
}