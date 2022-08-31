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

const int SZ = 100005;
const int INF = (int) 1e9;
int x[SZ], y[SZ], t[SZ];
int best[SZ];
int r, n;

int solve() {
    int ans = 0;
    int bb = -INF, bi = 0;
    best[0] = 0;
    FOR(i, 1, n+1) {
        while (t[i] - t[bi] > 2 * r) {
            bb = max(bb, best[bi++]);
        }
        int cb = bb;
        FOR(j, bi, i)
            if (abs(x[i]-x[j]) + abs(y[i]-y[j]) <= t[i] - t[j])
                cb = max(cb, best[j]);
        best[i] = 1 + cb;
        ans = max(ans, best[i]);
    }
    return ans;
}

int main() {
    setIO();
    cin>>r>>n;
    FOR(i, 1, n+1) {
        cin>>t[i]>>x[i]>>y[i];
        x[i]--; y[i]--;
    }
    cout<<solve()<<"\n";
    return 0;
}