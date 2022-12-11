#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

const int N = 3e6 + 34;

ll n, k, b;
ll sum, cur;
int ans;
int go[N], a[N];
pair <int, int> lst[2000004];

pair<int, int> dfs(int v, int en) {
    //cerr << v << " " << en << "\n";
    if (v >= en) return make_pair(0, v);
    pair<ll, ll> t;
    if (lst[v].first != -1) {
        t = dfs(lst[v].second, en);
        return lst[v] = make_pair(t.first + lst[v].first, t.second);
    }
    t = dfs(go[v], en);
    return lst[v] = make_pair(t.first + 1, t.second);
}

ll gsum;

int main() {
    //freopen("a.in", "r", stdin);

    scanf("%I64d%I64d", &n, &k);
    for (int i = 0; i < n; i++) {
        scanf("%d", &a[i]);
        gsum += a[i];
        a[n + i] = a[i];
        a[n * 2 + i] = a[i];
    }
    for (int iq = 0; iq < k; iq++) {
        scanf("%I64d", &b);
        if (b >= gsum) {
            printf("1\n");
            continue;
        }
        sum = 0;
        cur = 0;
        for (int i = 0; i < n * 2; i++) {
            while (sum + a[cur] <= b) {
                sum += a[cur];
                cur++;
            }
            go[i] = cur;
            sum -= a[i];
        }
        for (int i = 0; i < n * 2; i++)
            lst[i] = make_pair(-1, -1);
        ans = n;
        for (int st = 0; st <= go[0]; st++)
            ans = min(ans, dfs(st, st + n).first);
        printf("%d\n", ans);
    }

    return 0;
}