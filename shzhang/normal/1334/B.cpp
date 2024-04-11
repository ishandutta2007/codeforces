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

int T;
int n, x;
int a[100005];

int main()
{
    scanf("%d", &T);
    for (int data = 1; data <= T; data++) {
        scanf("%d%d", &n, &x);
        for (int i = 1; i <= n; i++) scanf("%d", a + i);
        sort(a + 1, a + n + 1);
        ll cursum = 0; int ans = 0;
        for (int i = n; i >= 1; i--) {
            cursum += (ll)a[i];
            if (cursum >= (ll)(n-i+1) * (ll)x) {
                ans = max(ans, n - i + 1);
            }
        }
        printf("%d\n", ans);
    }
    return 0;
}