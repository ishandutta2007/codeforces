#include <cstdio>
#include <algorithm>
#include <map>

using namespace std;

#define ll long long

int nxt[300005]; int n;
int a[300005]; int cnt[300005];
map<int, int> nxt2[300005];

ll work(void)
{
    scanf("%d", &n);
    for (int i = 1; i <= n; i++) scanf("%d", a + i);
    nxt[n] = 0; nxt[n+1] = 0;
    for (int i = n - 1; i >= 1; i--) {
        if (a[i+1] == a[i]) {
            nxt[i] = i + 2;
        } else {
            nxt[i] = nxt2[i+1].count(a[i]) ? nxt2[i+1][a[i]] + 1 : 0;
        }
        if (nxt[i] && nxt[i] <= n) {
            swap(nxt2[i], nxt2[nxt[i]]);
            nxt2[i][a[nxt[i]]] = nxt[i];
        }
    }
    ll ans = 0; cnt[n+1] = cnt[n] = 0;
    for (int i = n - 1; i >= 1; i--) {
        cnt[i] = nxt[i] == 0 ? 0 : (cnt[nxt[i]] + 1);
        ans += (ll)cnt[i];
    }
    for (int i = 0; i <= n; i++) nxt2[i].clear();
    return ans;
}

int main()
{
    int q;
    scanf("%d", &q);
    for (int i = 1; i <= q; i++) {
        printf("%lld\n", work());
    }
    return 0;
}