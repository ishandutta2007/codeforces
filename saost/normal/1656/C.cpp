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
    cin >> n;
    FOR(i, 1, n) cin >> a[i];
}

void Process() {
    int c1 = 0, c0 = 0;
    FOR(i, 1, n) {
        if (a[i] == 1) c1 = 1;
        if (a[i] == 0) c0 = 1;
    }
    if (c1 == 0) cout << "YES\n";
    else {
        sort(a+1, a+n+1);
        FOR(i, 1, n) {
            int j = i;
            while (a[i] == a[j]) ++j;
            if (j <= n && a[i] + 1 == a[j]) {
                cout << "NO\n";
                return;
            }
            i = j - 1;
        }
        cout << "YES\n";
    }
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