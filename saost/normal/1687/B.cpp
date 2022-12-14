#include <bits/stdc++.h>
#define FOR(i,l,r) for(int i=(l); i<=(r); ++i)
#define REP(i,l,r) for(int i=(l); i<(r); ++i)
#define FORD(i,r,l) for(int i=(r); i>=(l); --i)
#define REPD(i,r,l) for(int i=(r)-1; i>=(l); --i)
using namespace std;
const int N = 1e5 + 5;
int n, m, a[N], ans[N], edge[N];

void Enter() {
    cin >> n >> m;
}

void Process() {
    FOR(i, 1, m) {
        cout << "? ";
        FOR(j, 1, m) cout << (i==j);
        cout << endl;
        cin >> edge[i];
    }
    FOR(i, 1, m) a[i] = i;
    sort(a + 1, a + m + 1, [] (int x, int y) { return edge[x] < edge[y]; });

    long long res = 0;
    FOR(i, 1, m) {
        int pos = a[i];
        cout << "? ";
        REP(j, 1, pos) cout << ans[j];
        cout << 1;
        FOR(j, pos+1, m) cout << ans[j];
        cout << endl;
        long long tmp; cin >> tmp;
        if (res + edge[pos] == tmp) res = tmp, ans[pos] = 1;
    }
    cout << "! " << res;
}

int main()
{
    #define file ""
    if (fopen(file".inp","r")) {
        freopen(file".inp","r",stdin);
        freopen(file".out","w",stdout);
    }
    Enter();
    Process();
}