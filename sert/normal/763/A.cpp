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

int n, x;
int u[N];
int cur, v1, v2;
vector <pair<int, int> > e;
int c[N], b;

int main() {
    init();

    scanf("%d", &n);
    for (int i = 1; i < n; i++) {
        scanf("%d%d", &v1, &v2);
        e.push_back({v1 - 1, v2 - 1});
    }
    for (int i = 0; i < n; i++)
        scanf("%d", c + i);
    for (auto q: e) {
        if (c[q.first] != c[q.second]) {
            b++;
            u[q.first]++;
            u[q.second]++;
        }
    }

    for (int i = 0; i < n; i++) {
        if (u[i] == b) {
            printf("YES\n%d\n", i + 1);
            return 0;
        }
    }

    printf("NO\n");
    return 0;
}