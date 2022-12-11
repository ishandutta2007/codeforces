#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
const int N = 1e6 + 34;
const ll md = 1e9 + 7;

ll ans = 1e9, cur;
ll a10, ost;
int l[N], d[N], sf[N], sum[N], cnt[N];
int lft;
vector <int> es[N];

int cnt_s(int k) {
    if (k <= 0) return 0;
    int res = 0;
    for (int i = 0; k > 0 && i <= 200; i++) {
        if (sum[i] < k) {
            k -= sum[i];
            res += i * sum[i];
        } else {
            res += i * k;
            k = 0;
        }
    }
    return res;
}
int n;
int main() {
    //freopen("a.in", "r", stdin);
    //freopen("a.out", "w", stdout);
    scanf("%d", &n);
    for (int i = 0; i < n; i++)
        scanf("%d", l + i);
    for (int i = 0; i < n; i++) {
        scanf("%d", d + i);
        sf[l[i]] += d[i];
        cnt[l[i]]++;
        es[l[i]].push_back(d[i]);
    }
    for (int i = 100001; i >= 0; i--)
        sf[i] += sf[i + 1];

    for (int i = 0; i <= 100000; i++) {
        if (cnt[i] == 0) continue;
        cur = sf[i + 1];
        cur += cnt_s(lft - cnt[i] + 1);
        ans = min(ans, cur);
        lft += cnt[i];
        for (int j = 0; j < es[i].size(); j++)
            sum[es[i][j]]++;
    }

    cout << ans;


    return 0;
}