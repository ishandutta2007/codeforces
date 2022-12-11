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

bool cmp(pair<int, int> a, pair<int, int> b) {
    return a.first - a.second < b.first - b.second;
}

int n, k;
pair <int, int> a[N];

int main() {
    init();

    scanf("%d%d", &n, &k);
    for (int i = 0; i < n; i++) scanf("%d", &a[i].first);
    for (int i = 0; i < n; i++) scanf("%d", &a[i].second);

    sort(a, a + n, cmp);

    int sum = 0;
    for (int i = 0; i < k; i++)
        sum += a[i].first;
    for (int i = k; i < n; i++)
        sum += min(a[i].first, a[i].second);

    printf("%d\n", sum);

    return 0;
}