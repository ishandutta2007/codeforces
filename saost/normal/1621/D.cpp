#include <bits/stdc++.h>
#define FOR(i,l,r) for(int i=l; i<=r; ++i)
#define REP(i,l,r) for(int i=l; i<r; ++i)
#define FORD(i,r,l) for(int i=r; i>=l; --i)
#define REPD(i,r,l) for(int i=r-1; i>=l; --i)
using namespace std;
const long long N = 505, INF = 1e15;
const int Gx[4] = {0,1,0,-1};
const int Gy[4] = {1,0,-1,0};
int t, n, a[N][N];
long long f[N][N];

struct Data {
    long long z;
    int x, y;
    bool operator < (const Data &p) const {
        return z > p.z;
    }
};

void Enter() {
    cin >> n;
    FOR(i, 1, n*2) FOR(j, 1, n*2) cin >> a[i][j];
}

void Process() {
    long long res = 0, s2;
    FOR(i, 1, n*2) FOR(j, 1, n*2) {
        if (i>n && j>n) res += a[i][j], a[i][j] = 0;
        f[i][j] = INF;
    }
    cout << res + min(min(min(min(min(min(min(a[n][n+1], a[n+1][n]), a[1][n*2]), a[n*2][1]), a[n][n*2]), a[n*2][n]), a[1][n+1]), a[n+1][1]) << '\n';
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