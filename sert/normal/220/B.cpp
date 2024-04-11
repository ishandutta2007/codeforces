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

const int N = (int)1e5 + 34;

int a[N], k[N], o[N];
vector <int> v;
int p[500][N];

int main() {
    init();
    int n, m, l, r;
    scanf("%d%d", &n, &m);
    for (int i = 0; i < n; i++) {
        scanf("%d", a + i);
        if (a[i] < N)
            k[a[i]]++;
    }

    for (int i = 1; i < N; i++) {
        if (k[i] >= i) {
            v.push_back(i);
        }
    }

    for (int i = 0; i < (int)v.size(); i++) {
        for (int j = 0; j < n; j++)
            p[i][j + 1] = p[i][j] + int(a[j] == v[i]);
    }

    int ans = 0;
    while (m--) {
        scanf("%d%d", &l, &r);
        ans = 0;
        for (int i = 0; i < (int)v.size(); i++) {
            if (p[i][r] - p[i][l - 1] == v[i])
                ans++;
        }
        printf("%d\n", ans);
    }

    return 0;
}