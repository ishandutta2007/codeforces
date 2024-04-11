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

int n, x, ans;
unordered_set <int> s;

int main() {
    init();

    scanf("%d", &n);
    for (int i = 0; i < n * 2; i++) {
        scanf("%d", &x);
        if (s.find(x) == s.end())
            s.insert(x);
        else
            s.erase(x);
        ans = max(ans, (int)s.size());
    }

    printf("%d\n", ans);

    return 0;
}