#include <bits/stdc++.h>

using namespace std;

typedef long long LL;
typedef pair<int,int> pii;

int T;
int n, a[100010];

int main() {
    scanf("%d",&T);
    while(T--) {
        scanf("%d",&n);
        for (int i = 1; i <= n; i++) {
            scanf("%d",&a[i]);
        }
        sort(a + 1, a + n + 1);
        LL ans = a[n];
        LL s = 0;
        for (int i = 2; i <= n; i++) {
            ans -= 1LL * (i - 1) * a[i] - s;
            s += a[i];
        }
        printf("%lld\n",ans);
    }
}