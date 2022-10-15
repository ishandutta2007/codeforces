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
int a[200005];
int b[200005];

int main()
{
    scanf("%d", &n);
    for (int i = 1; i <= n; i++) scanf("%d", a + i);
    for (int i = 1; i <= n; i++) scanf("%d", b + i);
    int a_pos1 = 0, b_pos1 = 0;
    for (int i = 1; i <= n; i++) {
        if (a[i] == 1) a_pos1 = i;
        if (b[i] == 1) b_pos1 = i;
    }
    vector<int> x, y;
    for (int i = a_pos1; i <= n; i++) {
        if (a[i]) x.push_back(a[i]);
    }
    for (int i = 1; i < a_pos1; i++) {
        if (a[i]) x.push_back(a[i]);
    }
    for (int i = b_pos1; i <= n; i++) {
        if (b[i]) y.push_back(b[i]);
    }
    for (int i = 1; i < b_pos1; i++) {
        if (b[i]) y.push_back(b[i]);
    }
    for (int i = 0; i < x.size(); i++) {
        if (x[i] != y[i]) {
            printf("NO"); return 0;
        }
    }
    printf("YES");
    return 0;
}