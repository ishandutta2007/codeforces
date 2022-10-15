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

int t, n, m, k;
int a[3505];

int work(void)
{
    scanf("%d%d%d", &n, &m, &k);

    for (int i = 1; i <= n; i++) {
        scanf("%d", a + i);
    }
    if (k >= m - 1) {
        int maxval = 0;
        for (int i = 1; i <= m; i++) {
            maxval = max(maxval, a[i]);
        }
        for (int i = n - m + 1; i <= n; i++) {
            maxval = max(maxval, a[i]);
        }
        return maxval;
    }
    int ans = 0;
    for (int left = 0; left <= k; left++) {
        int round_min = 2000000000;
        for (int otherleft = 0; otherleft <= m - 1 - k; otherleft++) {
            int first_index = left + otherleft + 1;
            int last_index = n - ((m-1) - left - otherleft);
            //printf("%d %d %d %d\n", left, otherleft, first_index, last_index);
            round_min = min(round_min, max(a[first_index], a[last_index]));
        }
        ans = max(ans, round_min);
    }
    return ans;
}

int main()
{
    scanf("%d", &t);
    for (int i = 1; i <= t; i++) {
        printf("%d\n", work());
    }
    return 0;
}