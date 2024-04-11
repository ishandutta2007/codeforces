#include <cstdio>
#include <algorithm>
#include <vector>
#include <iostream>
#include <set>
#include <cstring>
#include <cstdlib>

using namespace std;

#define ll long long

int n, k, l;
ll a[100005];

int main()
{
    scanf("%d%d%d", &n, &k, &l);
    for (int i = 1; i <= n * k; i++) {
        int tmp;
        scanf("%d", &tmp);
        a[i] = tmp;
    }
    sort(a + 1, a + n * k + 1);
    int lastvol = 1;
    n = n * k;
    while (lastvol + k - 1 <= n && a[lastvol] - a[1] <= l) lastvol++;
    lastvol--;
    int next_after = lastvol + 1;
    ll ans = 0;
    int barrel_cnt = 0;
    while (lastvol > 0) {
        //printf("%d ", lastvol);
        if (next_after + k - 2 <= n) {
            next_after += k - 1; ans += a[lastvol]; lastvol--; barrel_cnt++;
        } else if (next_after <= n) {
            int available_after = n - next_after + 1;
            next_after = n + 1; lastvol -= k - available_after; ans += a[lastvol + 1];
            barrel_cnt++;
        } else {
            lastvol -= k; ans += a[lastvol + 1]; barrel_cnt++;
        }
    }
    if (barrel_cnt < n / k) {
        printf("0"); return 0;
    }
    cout << ans;
    return 0;
}