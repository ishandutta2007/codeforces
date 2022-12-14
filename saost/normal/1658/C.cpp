#include <bits/stdc++.h>
#define FOR(i,l,r) for(int i=l; i<=r; ++i)
#define REP(i,l,r) for(int i=l; i<r; ++i)
#define FORD(i,r,l) for(int i=r; i>=l; --i)
#define REPD(i,r,l) for(int i=r-1; i>=l; --i)
using namespace std;
const int N = 1e6 + 5;
long long t, l, r, n, cnt;
int a[N], b[N], f[N], ans[N], ll[N], rr[N];

void Enter() {
    cin >> n;
    REP(i, 0, n) cin >> a[i];
}

void Process() {
    int tmp = 0, pos = -1;
    REP(i, 0, n) if (a[i] == 1) pos = i, ++tmp;
    if (tmp != 1) return (void) (cout << "NO\n");
    REP(i, 0, n - 1)
        if (a[(i + pos) % n] + 1 < a[(i + pos + 1) % n]) return (void) (cout << "NO\n");
    cout << "YES\n";
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