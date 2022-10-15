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

int t, n;
int a[100005];

int main()
{
    scanf("%d", &t);
    for (int d = 1; d <= t; d++) {
        scanf("%d", &n);
        for (int i = 1; i <= n; i++) scanf("%d", a + i);
        int bits = 0;
        for (int i = 2; i <= n; i++) {
            if (a[i] < a[i-1]) {
                bits |= a[i-1] - a[i];
                a[i] = a[i-1];
            }
        }
        for (int i = 30; i >= 0; i--) {
            if (bits & (1 << i)) {
                printf("%d\n", i+1); goto loop_end;
            }
        }
        printf("0\n");
        loop_end: ;
    }
    return 0;
}