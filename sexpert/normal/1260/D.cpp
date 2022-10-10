#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

const int MAXN = 2e5 + 5;
int m, n, k, t;
vector<int> ev[MAXN];

bool can(int m) {
    int x = 0, cur = 0;
    for(int p = 0; p <= n + 1; p++) {
        for(auto x : ev[p]) {
            if(abs(x) > m) {
                if(x > 0)
                    cur++;
                else
                    cur--;
            }
        }
        x += (cur > 0);
    }
    return 2*x + n + 1 <= t;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    cin >> m >> n >> k >> t;
    vector<int> str(m);
    for(auto &x : str)
        cin >> x;
    for(int i = 0; i < k; i++) {
        int l, r, s;
        cin >> l >> r >> s;
        ev[l].push_back(s);
        ev[r + 1].push_back(-s);
    }
    int lo = 1, hi = MAXN;
    while(lo < hi) {
        int mi = (lo + hi)/2;
        if(can(mi))
            hi = mi;
        else
            lo = mi + 1;
    }
    int ans = 0;
    for(auto x : str)
        ans += (x >= lo);
    cout << ans << '\n';
}