#include <bits/stdc++.h>
#define FOR(i, l, r) for(int i=l; i<=r; i++)
#define FORD(i, r, l) for(int i=r; i>=l; i--)
#define REP(i, l, r) for(int i=l; i<r; i++)
using namespace std;
int t, n, m, x;
long double res, tile;

int main()
{
    ios_base::sync_with_stdio(false);cin.tie(NULL);
    cin >> t;
    while (t--) {
        cin>>n>>m;
        int now = 0;
        FOR(i, 1, n) { cin>>x; if (x!=i) now = i; }
        long double k = 1;
        FOR(i, 1, m) {
            cin>>x>>tile;
            if (x >= now) k = k * (1.0 - tile);
        }
        if (!now) res = 1; else res = 1.0 - k;
        cout << setprecision(6) << fixed << res << '\n';
    }
}