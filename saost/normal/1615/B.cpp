#include <bits/stdc++.h>
#define FOR(i,l,r) for(int i=l; i<=r; ++i)
#define REP(i,l,r) for(int i=l; i<r; ++i)
#define FORD(i,r,l) for(int i=r; i>=l; --i)
#define REPD(i,r,l) for(int i=r-1; i>=l; --i)
using namespace std;
const int N = 100005;
int t, l, r, res;

int main()
{
    ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
    cin >> t;
    while (t--) {
        cin >> l >> r;
        int ll = l - 1, rr = r, l2 = 1, r2 = 1;
        res = 0;
        REP(i, 0, 20) {
            res = max(res, rr/2 * (1<<i) + (rr&1) * r2 - (ll/2 * (1<<i) + (ll&1) * l2));
            r2 += (rr&1) << i;
            l2 += (ll&1) << i;
            ll /= 2;
            rr /= 2;
        }
        cout << r - l + 1 - res << '\n';
    }
}