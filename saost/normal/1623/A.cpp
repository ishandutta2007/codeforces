#include <bits/stdc++.h>
#define FOR(i,l,r) for(int i=l; i<=r; ++i)
#define REP(i,l,r) for(int i=l; i<r; ++i)
#define FORD(i,r,l) for(int i=r; i>=l; --i)
#define REPD(i,r,l) for(int i=r-1; i>=l; --i)
using namespace std;
const int N = 100005;
int t, n, m, k, res, res2, xa, xb, ya, yb;
int a[N], b[N], f[N];

void Enter() {
    cin >> m >> n >> xa >> ya >> xb >> yb;
}

void Process() {
    if (xa <= xb) res = xb - xa; else res = m*2 - xa - xb;
    if (ya <= yb) res2 = yb - ya; else res2 = n*2 - ya - yb;
    cout << min(res, res2) << '\n';
}

int main()
{
    ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
    cin >> t;
    while (t--) {
        Enter();
        Process();
    }
}