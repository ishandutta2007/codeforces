#include <bits/stdc++.h>
using namespace std;
#define M 300001
typedef long long ll;

int n, k, b, c;
int a[M], A[M];
ll pre[7][M];

ll calc(int st, int en) {
    int x = (en - st) / 5, y = (en - st) % 5;
    return 1ll * b * x + 1ll * c * y;
}

priority_queue<ll> S;


ll ok(int mod) {
    ll res = (1ll << 60);
    for(int i = 1; i <= n; i ++) A[i] = a[i];
    int x = A[k];
    while(x % 5 != mod) x ++;
    int ST = x;
    while(!S.empty()) S.pop();
    ll tot = 0;
    for(int i = 1; i <= k; i ++) {
        ll aa = pre[mod][i];
        S.push(aa);
        tot += aa;
    }
    res = min(res, tot);
    for(int i = k + 1; i <= n; i ++) {
        int y = A[i];
        while(y % 5 != mod) y ++;
        ll it = S.top();
        ll z = 1ll * (y - ST) / 5 * b;
        ll bb = calc(A[i], y) - z;
        if(bb < it) {
            tot -= it;
            tot += bb;
            res = min(res, tot + 1ll * k * z);
            S.pop();
            S.push(bb);
        }
    }
    return res;
}

void prepare() {
    for(int mod = 0; mod < 5; mod ++) {
        int x = a[k];
        while(x % 5 != mod) x ++;
        for(int i = 1; i <= k; i ++) {
            pre[mod][i] = calc(a[i], x);
        }
    }
}

int main() {
    ///freopen("cc.in", "r", stdin);
    scanf("%d %d %d %d", &n, &k, &b, &c);
    if(b > 5 * c) b = 5 * c;
    for(int i = 1; i <= n; i ++) scanf("%d", &a[i]), a[i] += (1e9);
    sort(a + 1, a + n + 1);
    prepare();
    ll ans = (1ll << 60);
    for(int i = 0; i < 5; i ++) ans = min(ans, ok(i));
    cout << ans << endl;
}