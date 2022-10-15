#include <cstdio>
#include <algorithm>
#include <vector>
#include <set>
#include <queue>
#include <algorithm>
#include <cstdlib>
#include <cstring>
#include <cmath>
#include <iostream>
#include <utility>

using namespace std;

#define ll long long

int n, k;
int a[100005];
int psum[100005];

bool work(void)
{
    scanf("%d%d", &n, &k);
    bool found = false;
    for (int i = 1; i <= n; i++) {
        scanf("%d", a + i);
        if (a[i] == k) found = true;
    }
    if (!found) return false;
    if (n == 1) return true;
    int min_psum = 1000000000;
    for (int i = 1; i <= n; i++) {
        psum[i] = psum[i-1] + (a[i] >= k ? 1 : -1);
        if (i >= 2) min_psum = min(min_psum, psum[i - 2]);
        if (psum[i] - min_psum > 0) return true;
    }
    return false;
}

int main()
{
    int t;
    scanf("%d", &t);
    for (int i = 1; i <= t; i++) {
        printf("%s\n", work() ? "yes" : "no");
    }
    return 0;
}