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

using namespace std;

#define ll long long

void work(void)
{
    int n, x;
    scanf("%d%d", &n, &x);
    int maxv = 0; bool equal = false;
    for (int i = 1; i <= n; i++) {
        int a;
        scanf("%d", &a); maxv = max(maxv, a);
        if (a == x) equal = true;
    }
    if (equal) {
        printf("1\n");
    } else {
        printf("%d\n", max(2, x % maxv == 0 ? x / maxv : x / maxv + 1));
    }
}

int main()
{
    int t;
    scanf("%d", &t);
    for (int i = 1; i <= t; i++) {
        work();
    }
    return 0;
}