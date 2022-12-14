#include <bits/stdc++.h>
#define FOR(i,l,r) for(int i=l; i<=r; ++i)
#define REP(i,l,r) for(int i=l; i<r; ++i)
#define FORD(i,r,l) for(int i=r; i>=l; --i)
#define REPD(i,r,l) for(int i=r-1; i>=l; --i)
using namespace std;
const int N = 100005;
int t, n, m, k, res;
int a[N], b[N], f[N], cc[N];

void Enter() {
    cin >> n;
    FOR(i, 0, 3) cin >> a[i] >> b[i];
}

void Process() {
    FOR(i, 0, 2) cc[i] = 0;
    FOR(i, 0, 2) FOR(j, i + 1, 2) if (abs(a[i] - a[j]) + abs(b[i] - b[j]) == 1) ++cc[i], ++cc[j];
    FOR(i, 0, 2) if (cc[i] == 2 && (a[i] == 1 || a[i] == n) && (b[i] == 1 || b[i] == n)) {
        if (a[i] == a[3] || b[i] == b[3]) cout << "YES\n";
        else cout << "NO\n";
        return;
    }
    FOR(i, 0, 2) if ((a[i] + a[3]) % 2 == 0 && (b[i] + b[3]) % 2 == 0) {
        cout << "YES\n";
        return;
    }
    cout << "NO\n";
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