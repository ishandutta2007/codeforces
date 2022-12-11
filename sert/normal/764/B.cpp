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

int main() {
    //init();

    scanf("%d", &n);
    for (int i = 0; i < n; i++)
        scanf("%d", a + i);
    for (int i = 0; i < n - i; i += 2)
        swap(a[i], a[n - i - 1]);
    for (int i = 0; i < n; i++)
        printf("%d ", a[i]);
    return 0;
}