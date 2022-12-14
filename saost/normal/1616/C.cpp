#include <bits/stdc++.h>
#define FOR(i,l,r) for(int i=l; i<=r; ++i)
#define REP(i,l,r) for(int i=l; i<r; ++i)
#define FORD(i,r,l) for(int i=r; i>=l; --i)
#define REPD(i,r,l) for(int i=r-1; i>=l; --i)
using namespace std;
const int N = 100005;
int t, n, cnt, a[N], b[N], res;
string s;

void Enter() {
    cin >> n;
    FOR(i, 1, n) cin >> a[i];
}

void Process() {
    res = 1;
    FOR(i, 1, n) FOR(j, i+1, n) {
        int dd = a[j] - a[i];
        FOR(w, 1, n)
        b[w] = a[w] * (j - i) + dd * (n - w);
        sort(b+1, b+n+1);
        FOR(i, 1, n) {
            int j = i;
            while (j<=n && b[i] == b[j]) ++j;
            res = max(res, j - i);
            i = j - 1;
        }
    }
    cout << n - res << '\n';
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