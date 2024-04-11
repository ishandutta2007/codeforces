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

void work()
{
    int n; scanf("%d", &n);
    vector<int> vec;
    bool has1 = false;
    for (int i = 1; i <= n; i++) {
        int a; scanf("%d", &a);
        if (a == 1) has1 = true;
        vec.push_back(a);
    }
    sort(vec.begin(), vec.end());
    bool hasdiff1 = false;
    for (int i = 1; i < n; i++) {
        if (vec[i] - vec[i-1] == 1) hasdiff1 = true;
    }
    if (!has1 || (!hasdiff1)) {
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