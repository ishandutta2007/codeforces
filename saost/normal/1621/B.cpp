#include <bits/stdc++.h>
#define FOR(i,l,r) for(int i=l; i<=r; ++i)
#define REP(i,l,r) for(int i=l; i<r; ++i)
#define FORD(i,r,l) for(int i=r; i>=l; --i)
#define REPD(i,r,l) for(int i=r-1; i>=l; --i)
using namespace std;
const int N = 100005;
int t, n, m, k, res;
int a[N], b[N], f[N];

void Enter() {
    cin >> n;
}

void Process() {
    int l = 2e9, r = 0, cost = 0, costL = 0, costR = 0, x, y, w;
    FOR(i, 1, n) {
        cin >> x >> y >> w;
        if (x < l) l = x, costL = w, cost = costL + costR;
        if (r < y) r = y, costR = w, cost = costL + costR;
        if (x == l) costL = min(costL, w), cost = min(cost, costL + costR);
        if (y == r) costR = min(costR, w), cost = min(cost, costL + costR);

        if (x == l && r == y) cost = min(cost, w);
        cout << cost << '\n';
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