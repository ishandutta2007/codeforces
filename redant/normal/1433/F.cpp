#include <bits/stdc++.h>
using namespace std;

typedef long long LL;
typedef vector<int> VI;
typedef pair<int,int> PI;

#define PB(x) push_back(x)
#define MP(x,y) make_pair(x,y)
#define F first
#define S second
#define FOR(i,a,b) for(int _n(b),i(a);i<_n;i++) 
#define REP(i,n) FOR(i,0,n)
#define ALL(v) (v).begin(),(v).end()
#define ITR(x,c) for(__typeof(c.begin()) x=c.begin();x!=c.end();x++)

void setIO() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
}

const int SZ = 71;
const int SZ2 = 36;
int a[SZ][SZ];
int n, m, k, mx;
int res[SZ], r2[SZ], r3[SZ];
int vis[SZ][SZ2][SZ*SZ2];

void go(int i, int j, int t, int sum) {
    if (j == m) {
        int sm = sum % k;
        r2[sm] = max(r2[sm], sum);
        return;
    }
    if (vis[j][t][sum] == i+1) return;
    vis[j][t][sum] = i+1;
    go(i, j + 1, t, sum);
    if (t < mx)
        go(i, j + 1, t + 1, sum + a[i][j]);
}

int solve() {
    mx = m / 2;
    REP(i, n) {
        REP(mod, k) r2[mod] = 0;
        go(i, 0, 0, 0);
        REP(mod, k) r3[mod] = 0;
        REP(sm, k) REP(rm, k)
            if (res[rm] && r2[sm]) {
                int rmod = (rm + sm) % k;
                r3[rmod] = max(r3[rmod], res[rm] + r2[sm]);
            }
        REP(mod, k) {
            res[mod] = max(res[mod], max(r2[mod], r3[mod]));
        }
    }
    return res[0];
}

int main() {
    setIO();
    cin>>n>>m>>k;
    REP(i, n) REP(j, m)
        cin>>a[i][j];
    cout<<solve()<<"\n";
    return 0;
}