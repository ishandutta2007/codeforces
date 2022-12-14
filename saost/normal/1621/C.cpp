#include <bits/stdc++.h>
#define FOR(i,l,r) for(int i=l; i<=r; ++i)
#define REP(i,l,r) for(int i=l; i<r; ++i)
#define FORD(i,r,l) for(int i=r; i>=l; --i)
#define REPD(i,r,l) for(int i=r-1; i>=l; --i)
using namespace std;
const int N = 100005;
int t, n, cnt, Q[N * 2];
int a[N], avail[N], ans[N];

void Enter() {
    cin >> n;
}

void Process() {
    FOR(i, 1, n) avail[i] = 0;
    cnt = 0;
    FOR(i, 1, n) if (!avail[i]) {
        int tmp = cnt;
        while (true) {
            cout << "? " << i << endl;
            cin >> Q[++cnt];
            if (avail[Q[cnt]]) break;
            avail[Q[cnt]] = 1;
        }
        int sz = cnt - tmp - 1;
        REP(j, tmp + 1, cnt)
            ans[Q[j]] = Q[(j - tmp) % sz + tmp + 1];
    }
    cout << "! ";
    FOR(i, 1, n) cout << ans[i] << ' ';
    cout << endl;
}

int main()
{
    cin >> t;
    while (t--) {
        Enter();
        Process();
    }
}