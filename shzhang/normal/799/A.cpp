#include <cstdio>
#include <iostream>
#include <algorithm>
#include <cstring>
#include <cstdlib>
#include <vector>
#include <set>
#include <queue>

using namespace std;

typedef long long ll;

#define div(a, b) (a % b == 0 ? a/b : 1+a/b)

int main()
{
    int n, t, k, d;
    scanf("%d%d%d%d", &n, &t, &k, &d);
    int time_no_oven = div(n, k) * t;
    /*int time_with_oven = 0;
    int curtime = 0;
    int remaining_1 = t;
    int remaining_2 = 0;
    while (n > 0) {
        remaining_1--;
        if (curtime > d) {
            remaining_2--;
        }
        if (remaining_1 == 0) {
            n -= k; remaining_1 = t;
        }
        if (curtime == d) remaining_2 = 0;
    }*/
    printf("%s", time_no_oven > d + t ? "YES" : "NO");
    return 0;
}