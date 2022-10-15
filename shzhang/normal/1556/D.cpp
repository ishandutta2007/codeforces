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

int n, k;
int andval[10005];
int orval[10005];
int xorval[10005];
int a[10005];

#define QUERY_AND 1
#define QUERY_OR 2

int query(int typ, int i, int j)
{
    printf("%s %d %d\n", typ == QUERY_AND ? "and" : "or", i, j);
    fflush(stdout);
    int res; scanf("%d", &res);
    return res;
}

int main()
{
    scanf("%d%d", &n, &k);
    for (int i = 2; i <= n; i++) {
        andval[i] = query(QUERY_AND, i-1, i);
        orval[i] = query(QUERY_OR, i-1, i);
        xorval[i] = orval[i] - andval[i];
    }
    int and12 = andval[2];
    int or12 = orval[2];
    int and23 = andval[3];
    //int or23 = orval[3];
    int and13 = query(QUERY_AND, 1, 3);
    int or13 = query(QUERY_OR, 1, 3);
    a[1] = (and12 | and13 | (or12 & or13 & (~and23)));
    for (int i = 2; i <= n; i++) {
        a[i] = (a[i-1] ^ xorval[i]);
    }
    sort(a + 1, a + n + 1);
    //for (int i = 1; i <= n; i++) printf("%d ", a[i]);
    printf("finish %d", a[k]);
    fflush(stdout);
    return 0;
}