#include <iostream>
#define FOR(i,l,r) for(int i=l; i<=r; i++)
using namespace std;
const int N = 1e5 + 5;
int t, n, res, a[N];

int main()
{
    ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
    cin >> t;
    while (t--) {
        cin >> n;
        FOR(i,1,n) cin >> a[i];
        int ok = true, ok1 = false, ok2 = false;
        int tang = 0, giam = 0;
        FOR(i,2,n) {
            if (a[i] >= a[i-1]) ok1 = true, tang = a[i] - a[i-1];
                else ok2 = true, giam = a[i] - a[i-1];
        }
        if (!ok1 || !ok2) res = 1e9+1; else res = tang - giam;
        if (a[1] >= res) ok = false;
        FOR(i,2,n) {
            if (a[i] >= res) { ok = false; break; }
            if (a[i] >= a[i-1]) {
                if (a[i-1] + tang != a[i]) { ok = false; break; }
            } else {
                if (a[i-1] + giam != a[i]) { ok = false; break; }
            }
        }
        if (!ok) cout << "-1\n";
        else {
            if (ok1 && ok2) cout << res << ' ' << tang << '\n';
            else cout << "0\n";
        }
    }
}