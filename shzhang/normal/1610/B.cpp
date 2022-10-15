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

bool ispalin(vector<int>& vec)
{
    if (vec.empty()) return true;
    int l = 0;
    int r = (int)vec.size() - 1;
    while (l < r) {
        if (vec[l] != vec[r]) return false;
        l++; r--;
    }
    return true;
}

int a[200005];

void work()
{
    int n; scanf("%d", &n);
    for (int i = 1; i <= n; i++) scanf("%d", a + i);
    vector<int> vec1, vec2;
    int l = 1, r = n;
    while (l < r) {
        if (a[l] != a[r]) break;
        l++; r--;
    }
    if (l > r) {
        printf("YES\n");
        return;
    }
    for (int i = 1; i <= n; i++) {
        if (a[i] != a[l]) vec1.push_back(a[i]);
        if (a[i] != a[r]) vec2.push_back(a[i]);
    }
    if (ispalin(vec1) || ispalin(vec2)) {
        printf("YES\n");
    } else {
        printf("NO\n");
    }
}

int main()
{
    int t; scanf("%d", &t);
    for (int i = 1; i <= t; i++) work();
    return 0;
}