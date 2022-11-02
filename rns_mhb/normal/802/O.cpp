#include <bits/stdc++.h>
using namespace std;
#define N 500010
#define inf 1e12
#define ep 1e-9
#define mp make_pair
#define pb push_back
#define ll long long
template<class T> void chkmax(T &a, T b) {if (a < b) a = b;}
template<class T> void chkmin(T &a, T b) {if (a > b) a = b;}
typedef pair<int, int> pii;

int n, k, a[N], b[N];

pair<ll, int> check(int c) {
    ll ans = 0, cnt = 0;
    priority_queue<int> qa, qb;
    for (int i = 1; i <= n; i ++) {
        qa.push(-a[i]);
        bool flag = 0;
        if (-qa.top() + b[i] < c) flag = 1;
        if (!qb.empty() && qb.top() > b[i]) flag = 1;
        if (!flag) continue;
        if (!qb.empty() && qb.top() - b[i] >= c - b[i] + qa.top()) {
            ans += qb.top() - b[i];
            qb.pop();
            qb.push(b[i]);

        }
        else {
            ans += c - b[i] + qa.top();
            qa.pop();
            qb.push(b[i]);
            cnt ++;
        }
    }
    return mp(ans, cnt);
}

int main() {
    scanf("%d%d", &n, &k);
    for (int i = 1; i <= n; i ++) scanf("%d", a + i);
    for (int i = 1; i <= n; i ++) scanf("%d", b + i);
    int l = 1, r = 2020202020, c;
    while (l + 1 < r) {
        int m = (1ll * l + r) / 2;
        int t = check(m).second;
        if (t < k) l = m;
        else if (t > k) r = m;
        else {
            l = m;
            break;
        }
    }
    printf("%I64d", 1ll * k * l - check(l).first);
}