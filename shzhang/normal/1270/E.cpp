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

int x[1005];
int y[1005];
int n;

int absolute(int a)
{
    return a < 0 ? -a : a;
}

int updiv(int a)
{
    if (a < 0) {
        return -((-a+1)/2);
    }
    return (a)/2;
}

int main()
{
    scanf("%d", &n);
    for (int i = 1; i <= n; i++) {
        scanf("%d%d", x + i, y + i);
    }
    while (1) {
        int odd_cnt = 0;
        for (int i = 1; i <= n; i++) {
            if (!(absolute(x[i] + y[i]) & 1)) odd_cnt++;
        }
        if (odd_cnt == 0 || odd_cnt == n) {
            for (int i = 1; i <= n; i++) {
                int oldx = x[i], oldy = y[i];
                x[i] = updiv(-oldx + oldy + 1);
                y[i] = updiv(oldx + oldy + 1);
            }
        } else {
            break;
        }
        //for (int i = 1; i <= n; i++) printf("%d %d\n", x[i], y[i]);
    }
    int cnt = 0;
    for (int i = 1; i <= n; i++) {
        if (absolute(x[i] + y[i]) & 1) cnt++;
    }
    printf("%d\n", cnt);
    for (int i = 1; i <= n; i++) {
        if (absolute(x[i] + y[i]) & 1) printf("%d ", i);
    }
    return 0;
}