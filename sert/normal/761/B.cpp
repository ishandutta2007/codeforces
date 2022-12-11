#include <bits/stdc++.h>
using namespace std;
#define TASKNAME "dynasties"
void init() {
#ifdef MOI_KOD_IDEALEN
    freopen("a.in", "r", stdin);
    //freopen("a.out", "w", stdout);
#else
    //freopen(TASKNAME".in", "r", stdin);
    //freopen(TASKNAME".out", "w", stdout);
#endif
}
typedef long long ll;
typedef long double ld;

const int N = (int)1e6 + 34;

int n, a[N];
int b[N], l, a0, b0;
bool fail;

int main() {
    init();

    scanf("%d%d", &n, &l);
    for (int i = 0; i < n; i++)
        scanf("%d", a + i);
    for (int i = 0; i < n; i++)
        scanf("%d", b + i);

    a0 = a[0];
    b0 = b[0];
    for (int i = 0; i < n - 1; i++) {
        a[i] = a[i + 1] - a[i];
        b[i] = b[i + 1] - b[i];
    }
    a[n - 1] = a0 + l - a[n - 1];
    b[n - 1] = b0 + l - b[n - 1];

    for (int i = 0; i < n; i++)
        b[n + i] = b[i];

    for (int i = 0; i < n; i++) {
        fail = false;
        for (int j = 0; j < n; j++)
            if (a[j] != b[i + j])
                fail = true;
        if (!fail) {
            printf("YES\n");
            return 0;
        }
    }
    printf("NO\n");

    return 0;
}