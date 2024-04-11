#include <bits/stdc++.h>
#define FOR(i,l,r) for(int i=l; i<=r; ++i)
#define REP(i,l,r) for(int i=l; i<r; ++i)
#define FORD(i,r,l) for(int i=r; i>=l; --i)
#define REPD(i,r,l) for(int i=r-1; i>=l; --i)
#define pii pair<long long,int>
using namespace std;
const int N = 100005;
int t, n, k, res, a[N], f[N];

void Process() {
}

int main()
{
    ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
    cin >> t;
    while (t--) {
        cin >> n;
        bool ok = true;
        for(int i=1; i<=n; ++i) {
            int x, pos = 0;
            cin >> x;
            for(int j=i; j; --j) if (x % (j+1) != 0) {
                pos = j;
                break;
            }
            if (pos == 0) {
                ok = false;
            }
        }
        cout << (ok ? "YES\n" : "NO\n");
    }
}