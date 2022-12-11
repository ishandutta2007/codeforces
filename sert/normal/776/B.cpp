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
const ll md = (ll)1e9 + 7;

bool u[N];

int main() {
    init();

    for (int i = 2; i < 10000; i++) {
        if (u[i]) continue;
        for (int j = i * i; j < N; j += i)
            u[j] = true;
    }

    int n;
    cin >> n;
    if (n == 1) printf("1\n1\n");
    if (n == 2) printf("1\n1 1\n");
    if (n < 3) return 0;

    printf("2\n");
    for (int i = 0; i < n; i++)
        printf("%d ", 1 + u[i + 2]);

    return 0;
}