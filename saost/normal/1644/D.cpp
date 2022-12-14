#include <bits/stdc++.h>
#define FOR(i,l,r) for(int i=(l); i<=(r); ++i)
#define REP(i,l,r) for(int i=(l); i<(r); ++i)
#define FORD(i,r,l) for(int i=(r); i>=(l); --i)
#define REPD(i,r,l) for(int i=(r)-1; i>=(l); --i)
using namespace std;
const int N = 2e5 + 5, MOD = 998244353;
int t, n, m, k, q, x[N], y[N];
int tmp, res, row[N], column[N];

void Enter() {
    cin >> m >> n >> k >> q;
    FOR(i, 1, q) cin >> x[i] >> y[i];
}

long long power(long long x, int k) {
    long long ans = 1;
    while (k) {
        if(k&1) ans = ans*x%MOD;
        x=x*x%MOD;
        k>>=1;
    }
    return ans;
}

void Process() {
    int c_row = m, c_column = n;
    ++tmp;
    res = 0;
    FORD(i, q, 1) {
        if (!c_row || !c_column) break;
        if (row[x[i]] == tmp && column[y[i]] == tmp) continue;
        if (row[x[i]] != tmp) row[x[i]] = tmp, --c_row;
        if (column[y[i]] != tmp) column[y[i]] = tmp, --c_column;
        ++res;
    }
    cout << power(k, res) << '\n';
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