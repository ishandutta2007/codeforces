#include <bits/stdc++.h>
using namespace std;
#define TASKNAME "sum"
void init() {
#ifdef MOI_KOD_IDEALEN
    freopen("a.in", "r", stdin);
    ///freopen("a.out", "w", stdout);
#else
    //freopen(TASKNAME".in", "r", stdin);
    //freopen(TASKNAME".out", "w", stdout);
#endif
}
typedef long long ll;
typedef long double ld;

const int N = 1e6 + 34;

int n, a[N];
int mn, mx, ans;

int main() {
    init();

    scanf("%d", &n);
    ans = n;
    for (int i = 0; i < n; i++)
        scanf("%d", a + i);
    mn = mx = a[0];
    for (int i = 1; i < n; i++) {
        if (a[i] < mn) mn = a[i];
        if (a[i] > mx) mx = a[i];
    }
    for (int i = 0; i < n; i++) {
        if (a[i] == mn || a[i] == mx)
            ans--;
    }

    printf("%d", max(ans, 0));

    return 0;
}