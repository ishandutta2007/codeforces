#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

const int MAXN = 2e5 + 5;
ll BIT[MAXN];

ll upd(int p, ll v) {
    for(; p < MAXN; p += (p & -p)) BIT[p] += v;
}

int search(ll targ) {
    int cur = 0;
    for(int k = 18; k >= 0; k--) {
        int l = (1 << k);
        if(cur + l < MAXN && BIT[cur + l] <= targ) {
            cur += l;
            targ -= BIT[cur];
        }
    }
    return cur;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int n;
    cin >> n;
    vector<ll> sums(n);
    vector<int> ans(n + 1);
    for(auto &x : sums)
        cin >> x;
    for(int i = 1; i <= n; i++)
        upd(i, i);
    upd(n + 1, 1);
    for(int i = n; i >= 1; i--) {
        int x = search(sums[i - 1]);
        ans[i] = x + 1;
        upd(ans[i], -ans[i]);
    }
    for(int i = 1; i <= n; i++)
        cout << ans[i] << " ";
    cout << '\n';
}