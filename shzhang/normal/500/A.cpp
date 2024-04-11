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

bool good[30005];
int a[30005];

int n, t;

int main()
{
    scanf("%d%d", &n, &t);
    for (int i = 1; i < n; i++) {
        scanf("%d", a + i);
    }
    int cur = 1;
    while (1) {
        cur += a[cur];
        if (cur == t) {
            printf("YES"); return 0;
        }
        if (cur > t) {
            printf("NO"); return 0;
        }
    }
    return 0;
}