#include <bits/stdc++.h>
using namespace std;
using ll = long long;

ll mem[205][205][205], ans = 0;
vector<ll> rr, gg, bb;

ll dp(int r, int g, int b) {
    if(mem[r][g][b] != -1)
        return mem[r][g][b];
    if((r == 0) + (g == 0) + (b == 0) >= 2)
        return mem[r][g][b] = 0;
    ll res = 0;
    if(r && g)
        res = max(res, dp(r - 1, g - 1, b) + rr[r - 1] * gg[g - 1]);
    if(b && g)
        res = max(res, dp(r, g - 1, b - 1) + bb[b - 1] * gg[g - 1]);
    if(r && b)
        res = max(res, dp(r - 1, g, b - 1) + rr[r - 1] * bb[b - 1]);
    return mem[r][g][b] = res;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int R, G, B;
    cin >> R >> G >> B;
    rr.resize(R);
    bb.resize(B);
    gg.resize(G);
    for(auto &x : rr)
        cin >> x;
    for(auto &x : gg)
        cin >> x;
    for(auto &x : bb)
        cin >> x;

    sort(rr.rbegin(), rr.rend());
    sort(gg.rbegin(), gg.rend());
    sort(bb.rbegin(), bb.rend());

    memset(mem, -1, sizeof mem);

    for(int r = 0; r <= R; r++) {
        for(int g = 0; g <= G; g++) {
            for(int b = 0; b <= B; b++) {
                ans = max(ans, dp(r, g, b));
            }
        }
    }

    cout << ans << '\n';
}