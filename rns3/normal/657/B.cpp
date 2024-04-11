#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define M 200100

int n;
ll a[M];
ll b[M];
int flag[M];
ll limit;

int main() {
    //freopen("B2.in", "r", stdin);
    scanf("%d", &n);
    scanf("%I64d", &limit);
    //printf("%d %I64d\n", n, limit);
    for (int i = 0; i <= n; i++) {
        scanf("%I64d", a + i);
    }

    b[n] = a[n];
    for (int i = n - 1; i >= 0; i--) {
        b[i] = b[i+1] * 2 + a[i];
        //printf("b[%d] = %I64d\n", i, b[i]);
        if (flag[i + 1] || b[i] > limit || b[i] < -limit) {
            flag[i] = 1;
        }
    }

    if (!flag[0] && b[0] == 0) {
        //puts("~~~~~~~~~~~~");
        puts("1");
        return 0;
    }

    int answer = 0;
    ll t = 0;
    for (int i = 0; i <= n; i++) {
        if (!flag[i + 1]) {
            ll x = -b[i+1] * 2 - t;
            //printf("i = %d, x = %I64d\n", i, x);
            if (x >= -limit && x <= limit) {
                if (i == n && !x);
                else answer++;
            }
        }
        t = t + a[i];
        if (t & 1) {
            break;
        }
        t >>= 1;
    }
    printf("%d\n", answer);
    return 0;
}