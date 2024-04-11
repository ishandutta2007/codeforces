#include <bits/stdc++.h>
using namespace std;

#define N 200005
#define INF 1e9

typedef long long ll;
typedef pair<int, int> pii;
int n, now;
int id[N];
ll a[N], s[N], b[N];
double ans;
pii ansarg;
int type;

bool cmp(int x, int y) {
    return a[x] < a[y];
}

double test(int k) {
    if (k > now - 1 || k > n - now) return -INF;
    ll tot = s[now] - s[now-k-1] + s[n] - s[n-k];
    return 1.0 * tot / (2 * k + 1) - 1.0 * b[now];
}

double test1(int k) {
    ll tot = s[now] - s[now-k-1] + s[n] - s[n-k] + b[now+1];
    return 1.0 * tot / (2 * k + 2) - 0.5 * (b[now] + b[now+1]);
}

int main() {
    scanf("%d", &n);
    for (int i = 1; i <= n; i ++) {
        scanf("%I64d", &a[i]);
        id[i] = i;
    }
    if (n == 1) {
        printf("1\n");
        printf("%d\n", a[1]);
        return 0;
    }
    sort(id + 1, id + n + 1, cmp);
    for (int i = 1; i <= n; i ++) {
        b[i] = a[id[i]];
        s[i] = s[i-1] + b[i];
    }
    ans = -INF;
    for (int i = 1; i <= n; i ++) {
//        cout<<b[i]<<endl;
        now = i;
//        cout<<test(1)<<endl;
        int st = 0, en = min(now - 1, n - now);
        while (st < en) {
//            cout<<st<<" "<<en<<endl;
//        cout<<test(st)<<" "<<test(st+1)<<" "<<test(st+2)<<endl;
            int mid = st + en >> 1;
            if (test(mid) < test(mid + 1)) st = mid + 1;
            else en = mid;
        }
//        if (test(st) < test(en)) st = en;
        if (ans < test(st)) {
            ansarg = pii(i, st); type = 1;
            ans = test(st);
        }
    }
    for (int i = 1; i < n; i ++) {
        now = i;
        int st = 0, en = min(now - 1, n - now - 1);
        while (st < en) {
            int mid = st + en >> 1;
            if (test1(mid) < test1(mid + 1)) st = mid + 1;
            else en = mid;
        }
//        if (test1(st) < test1(en)) st = en;
        if (ans < test1(st)) {
            ansarg = pii(i, st); type = 0;
            ans = test1(st);
        }
    }
    if (type == 1) {
        int now = ansarg.first, k = ansarg.second;
        printf("%d\n", 2 * k + 1);
        printf("%d ", b[now]);
        for (int i = 1; i <= k; i ++) printf("%d ", b[now-i]);
        for (int i = 1; i <= k; i ++) printf("%d ", b[n+1-i]);
    }
    else {
        int now = ansarg.first, k = ansarg.second;
//        cout<<now<<k<<endl;
        printf("%d\n", 2 * k + 2);
        for (int i = -1; i <= k; i ++) printf("%d ", b[now-i]);
        for (int i = 1; i <= k; i ++) printf("%d ", b[n+1-i]);
    }
}