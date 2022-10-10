#include <bits/stdc++.h>
using namespace std;
using ll = long long;

const int MAXN = 1e7;

int sz;
int to[MAXN][2], cnt[MAXN][2];
ll inv[MAXN];
ll res[40][2];

void add(int x) {
    int cur = 0;
    for(int b = 29; b >= 0; b--) {
        int di = (x >> b) & 1;
        if(di == 0)
            inv[cur] += cnt[cur][1];
        cnt[cur][di]++;
        if(!to[cur][di])
            to[cur][di] = ++sz;
        cur = to[cur][di];
    }
}

void trav(int s, int h) {
    res[h][0] += inv[s];
    res[h][1] += (ll)cnt[s][0] * (ll)cnt[s][1] - inv[s];
    if(to[s][0])
        trav(to[s][0], h - 1);
    if(to[s][1])
        trav(to[s][1], h - 1);
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int n;
    cin >> n;
    for(int i = 1; i <= n; i++) {
        int x;
        cin >> x;
        add(x);
    }
    trav(0, 29);

    ll ans = 0;
    ll mask = 0;
    for(int b = 29; b >= 0; b--) {
        ans += min(res[b][0], res[b][1]);
        //cout << res[b][0] << " " << res[b][1] << endl;
        if(res[b][1] < res[b][0])
            mask |= (1 << b);
    }
    cout << ans << " " << mask << '\n';
}