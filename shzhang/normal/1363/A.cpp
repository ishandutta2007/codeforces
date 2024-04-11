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

int main()
{
    int t;
    scanf("%d", &t);
    for (int d = 1; d <= t; d++) {
        int n, x;
        int oddcnt = 0, evencnt = 0;
        scanf("%d%d", &n, &x);
        for (int i = 1; i <= n; i++) {
            int a; scanf("%d", &a);
            if (a%2) oddcnt++;
            else evencnt++;
        }
        for (int i = 0; i <= oddcnt; i++) {
            int j = x - i;
            if (j < 0) continue;
            if (j > evencnt) continue;
            if (i % 2) {
                printf("Yes\n"); goto loop_end;
            }
        }
        printf("No\n");
        loop_end:
        ;
    }
    return 0;
}