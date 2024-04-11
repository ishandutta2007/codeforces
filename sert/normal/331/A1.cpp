#include <bits/stdc++.h>
using namespace std;

#define scanf(a, b) assert(scanf(a, b) != -1)
#define TASKNAME "cactus"
void init() {
#if __gnu_linux__ == 1
    assert(freopen("a.in", "r", stdin));
    //freopen("a.out", "w", stdout);
#else
    //freopen(TASKNAME".in", "r", stdin);
    //freopen(TASKNAME".out", "w", stdout);
#endif
}

typedef long long ll;
typedef long double ld;
const int N = (int)2e5 + 34;
const ll INF = (ll)1e18 + 34;
const ll md = (ll)1e9 + 7;

unordered_map <int, pair<ll ,int>> mn;

ll minsp[N];
ll bst = -INF;
int l, r;
ll sump, cur;
pair <ll, int> kek;
int n, a[N];

int main() {
    init();

    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        scanf("%d", a + i);
        mn[a[i]] = {INF, -1};
    }

    for (int i = 0; i < n; i++) {
        kek = mn[a[i]];
        cur = sump - kek.first + a[i] * 2;

        //cerr << i << " " << sump << " " << cur << "\n";

        if (cur > bst) {
            bst = cur;
            l = kek.second;
            r = i;
        }

        sump += max(0, a[i]);
        kek = {sump, i};
        if (mn[a[i]] > kek)
            mn[a[i]] = kek;
    }

    //cerr << bst << " " << l << " " << r << "\n";

    vector <int> del;
    for (int i = 0; i < n; i++)
        if (i < l || i > r || (l < i && i < r && a[i] <= 0))
            del.push_back(i + 1);

    printf("%I64d %d\n", bst, (int)del.size());
    for (auto d: del)
        printf("%d ", d);

    return 0;
}