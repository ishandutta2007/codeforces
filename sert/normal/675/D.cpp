#include <bits/stdc++.h>
using namespace std;
const int N = 1e5 + 34;
set <pair<int, int> > s;
set <pair<int, int> > :: iterator it;
int lca[N], n, x, r, l, a[N];

int main() {
    //freopen("a.in", "r", stdin);
    scanf("%d", &n);
    scanf("%d", a);
    s.insert({a[0], 0});
    s.insert({1000000001, -34});
    s.insert({-1000000001, -34});

    for (int i = 1; i < n; i++) {
        scanf("%d", a + i);
        x = a[i];
        it = s.lower_bound({x, 0});
        r = it->second;
        it--;
        l = it->second;

        if (l == -34 || (lca[l] < x && r != -34)) {
            lca[i] = a[r];
            printf("%d ", a[r]);
        } else {
            lca[i] = lca[l];
            lca[l] = a[l];
            printf("%d ", a[l]);
        }

        s.insert({x, i});
    }

    return 0;
}