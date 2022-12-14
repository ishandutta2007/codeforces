#include <bits/stdc++.h>
using namespace std;
void init() {
#if __GNUG__ == 4 && __GNUC_MINOR__ == 9 ///my GNU version is 4.9.3
    freopen("a.in", "r", stdin);
    ///freopen("a.out", "w", stdout);
#endif
}
typedef long long ll;
typedef long double ld;

const int N = 1e6 + 34;
const int INF = 1e9 + 34;

set <int> s[N];
int pr[N];
int ans;
int lst = 0;
int n, q, t, x, len;

int main() {
    init();

    scanf("%d%d", &n, &q);

    for (int iq = 0; iq < q; iq++) {
        scanf("%d%d", &t, &x);

        if (t == 1) {
            s[x].insert(len);
            pr[len++] = x;
            ans++;
        }
        if (t == 2) {
            ans -= s[x].size();
            s[x].clear();
        }
        if (t == 3) {
            for (int i = lst; i < x; i++) {
                if (s[pr[i]].find(i) != s[pr[i]].end()) {
                    ans--;
                    s[pr[i]].erase(i);
                }
            }
            lst = max(lst, x);
        }
        printf("%d\n", ans);
    }


    return 0;
}