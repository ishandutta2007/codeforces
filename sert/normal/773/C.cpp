#include <bits/stdc++.h>
using namespace std;
#define TASKNAME "sum"
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
const ll md = (int)1e9 + 7;

int n;
ll a[N], x, d;
int k[N];
int p[N];
ll max_st;

int main() {
    /*freopen("a.out", "w", stdout);
    for (ll i = 0; i < 40; i++)
        printf("%I64d ", (1ll << i));
    return 0;*/

    init();
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        scanf("%I64d", a + i);
        x = a[i];
        d = -1;
        while (x > 0) {
            x >>= 1;
            d++;
        }
        if ((1ll << d) == a[i]) {
            if (k[d] == 0)
                p[d] = i;
            k[d]++;
        }
    }

    max_st = 0;
    while (k[max_st + 1]) max_st++;

    //cerr << max_st << "\n";

    //cerr << a[n - 1] << " " << (2ll << max_st) << "\n";

    if (a[n - 1] > (2ll << max_st)) {
        printf("-1\n");
        return 0;
    }

    //cerr << "kek\n";

    vector <int> ans;
    for (int m = 1; m <= n; m++) {
        int e = 0;
        int fri = m;
        int lst = m;
        //cerr << k[0] << "\n";
        if (k[0] < m) continue;
        bool fail = false;
        for (int i = 1; !fail && i <= max_st; i++) {
            fri -= (p[i] - (p[i - 1] + lst));
            lst = min(k[i], lst);
            fri = min(k[i], fri);
            if (fri < 0) fail = true;
        }

        if (!fail && fri >= (n - (p[max_st] + lst)))
            ans.push_back(m);
    }

    if (ans.empty()) {
        printf("-1");
        return 0;
    }

    //printf("%d\n", ans.size());
    for (int i = 0; i < (int)ans.size(); i++)
        printf("%d ", ans[i]);

    return 0;
}