#include <bits/stdc++.h>

using namespace std;

typedef long long LL;
typedef pair<int,int> pii;

int T;
int n;
LL a[400010];

int main() {
    scanf("%d",&T);
    while(T--) {
        scanf("%d",&n);
        for (int i = 1; i <= n; i++) {
            scanf("%lld",&a[i]);
        }
        a[0] = a[n + 1] = 0;
        LL ans = 0;
        for (int i = 1; i <= n; i++) {
            if (a[i] > a[i - 1] && a[i] > a[i + 1]) {
                LL delta = a[i] - max(a[i - 1], a[i + 1]);
                ans += delta;
                a[i] -= delta;
            }
        }
        for (int i = 1; i <= n + 1; i++) {
            ans += abs(a[i] - a[i - 1]);
        }
        printf("%lld\n",ans);
    }
}