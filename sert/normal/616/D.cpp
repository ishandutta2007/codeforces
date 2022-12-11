#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N = 1e6 + 34;
typedef long double ld;

int lst[N], nx[N], a[N];
int ans = -1, l, r, cur, df;
int u[N], n, k;

int main() {
    //freopen("a.in", "r", stdin);
    scanf("%d%d", &n, &k);
    for (int i = 0; i < n; i++)
        scanf("%d", a + i);

    for (int i = 0; i < n; i++) {
        while (cur < n) {
            if (!u[a[cur]]) {
                if (df == k)
                    break;
                df++;
            }
            u[a[cur]]++;
            cur++;
        }
        if (cur - i > ans) {
            ans = cur - i;
            l = i + 1;
            r = cur;
        }
        //cerr << i + 1 << " " << cur << "\n";
        u[a[i]]--;
        if (!u[a[i]])
            df--;
    }

    printf("%d %d\n", l, r);

    return 0;
}