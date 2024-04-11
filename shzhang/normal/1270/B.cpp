#include <cstdio>
#include <vector>
#include <set>
#include <cstdlib>
#include <queue>
#include <iostream>
#include <algorithm>
#include <utility>
#include <cmath>
#include <cstring>

using namespace std;

#define ll long long

int absolute(int a)
{
    return a < 0 ? -a : a;
}

void work(void)
{
    vector<int> a; int n;
    scanf("%d", &n);
    for (int i = 1; i <= n; i++) {
        int x;
        scanf("%d", &x);
        a.push_back(x);
    }
    for (int i = 0; i + 1 < n; i++) {
        if (absolute(a[i] - a[i+1]) > 1) {
            printf("YES\n");
            printf("%d %d\n", i+1, i+2);
            return;
        }
    }
    printf("NO\n");
    return;
}

int main()
{
    int t;
    scanf("%d", &t);
    for (int i = 1; i <= t; i++) work();
    return 0;
}