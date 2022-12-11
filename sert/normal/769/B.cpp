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

int n;
pair <int, int> a[N];
vector <pair<int, int> > ans;

int main() {
    init();

    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &a[i].first);
        a[i].second = i + 1;
        a[i].first = -a[i].first;
    }

    sort(a + 1, a + n);

    int cur = 1, x;
    for (int i = 0; i < n; i++) {
        if (cur <= i) {
            printf("-1\n");
            return 0;
        }
        x = -a[i].first;
        for (int j = 0; j < x && cur < n; j++, cur++) {
            ans.push_back({a[i].second, a[cur].second});
        }
    }

    printf("%d\n", ans.size());
    for (auto q: ans) {
        printf("%d %d\n", q.first, q.second);
    }

    return 0;
}