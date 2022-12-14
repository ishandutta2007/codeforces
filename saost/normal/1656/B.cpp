#include <bits/stdc++.h>
#define FOR(i,l,r) for(int i=l; i<=r; ++i)
#define REP(i,l,r) for(int i=l; i<r; ++i)
#define FORD(i,r,l) for(int i=r; i>=l; --i)
#define REPD(i,r,l) for(int i=r-1; i>=l; --i)
using namespace std;
const int N = 200005;
int t, n, m, k, res;
int a[N], b[N], f[N];

void Enter() {
    cin >> n >> m;
    FOR(i, 1, n) cin >> a[i];
}

void Process() {
    sort(a+1, a+n+1);
    int j = 1;
    FOR(i, 1, n) {
        while (j < n && a[j] - a[i] < m) ++j;
        if (j != i && a[j] - a[i] == m) {
            cout << "YES\n";
            return;
        }
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