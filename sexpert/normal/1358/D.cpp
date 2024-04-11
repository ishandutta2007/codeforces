#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

const int MAXN = 2e5 + 10;
int n;
ll x, v[2*MAXN], ps[2*MAXN], pss[2*MAXN];

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int n;
    cin >> n >> x;
    for(int i = 1; i <= n; i++)
        cin >> v[i];
    for(int i = n + 1; i <= 2*n; i++)
        v[i] = v[i - n];
    ll ans = 0;
    for(int i = 1; i <= 2*n; i++)
        ps[i] = ps[i - 1] + v[i];
    for(int i = 1; i <= 2*n; i++)
        pss[i] = pss[i - 1] + (v[i] * (v[i] + 1))/2;
    for(int i = 1; i <= n; i++) {
        int lo = i - 1, hi = 2*n;
        ll cnt = x;
        while(lo < hi) {
            int mi = (lo + hi + 1)/2;
            if(ps[mi] - ps[i - 1] <= cnt)
                lo = mi;
            else
                hi = mi - 1;
        }
        ll res = pss[lo] - pss[i - 1];
        cnt -= (ps[lo] - ps[i - 1]);
        res += (((ll)v[lo + 1] * cnt) - cnt*(cnt - 1)/2);
        //cout << i << " " << lo << " " << cnt << " " << res << endl;
        ans = max(ans, res);
    }
    cout << ans << '\n';
}