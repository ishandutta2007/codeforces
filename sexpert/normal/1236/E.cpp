#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int MAXN = 1e5 + 10;

int n, m, cnt[2*MAXN];
ll tot[2];

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    cin >> n >> m;
    vector<int> a(m);
    ll ans = n;
    for(auto &x : a)
        cin >> x;

    if(n == 1) {
        cout << "0\n";
        return 0;
    }

    vector<int> v(n + 1);

    // find left
    for(int re = 0; re < 2; re++) {
        fill(cnt, cnt + 2*MAXN, 0);
        for(int i = 1; i <= n; i++)
            cnt[i] = 1;
        for(int i = 0; i < m; i++) {
            int nag = a[i] + i + 1;
            cnt[nag + 1] += cnt[nag];
            cnt[nag] = 0;   
        }
        for(int i = 0; i < 2 * MAXN; i++) {
            if(re == 0)
                tot[0] += (ll)cnt[i] * max(1, i - m - 1);
            else
                tot[1] += (ll)cnt[i] * (n + 1 - max(1, i - m - 1));
        }
        reverse(a.begin(), a.end());
    }

    cout << tot[1] - tot[0] + n << '\n';
}