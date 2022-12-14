#include <bits/stdc++.h>
#define FOR(i,l,r) for(int i=l; i<=r; ++i)
#define REP(i,l,r) for(int i=l; i<r; ++i)
#define FORD(i,r,l) for(int i=r; i>=l; --i)
#define REPD(i,r,l) for(int i=r-1; i>=l; --i)
using namespace std;
const int N = 100005;
int t, n, m, k, res;
int a[N], b[N], f[N];
vector<pair<int, int>> Q;

void Enter() {
    cin >> n;
}

void Process() {
    int ii = 0;
    int sz = (n * 2 + 1) / 3;
    FOR(i, 1, (sz + 1) / 2) {
        Q.emplace_back(i*2 - 1, ++ii);
    }
    FOR(i, 1, sz / 2) {
        Q.emplace_back(i*2, ++ii);
    }
    cout << Q.size() << '\n';
    for(auto [u, v] : Q) cout << u << ' ' << v << '\n';
}

int main()
{
    ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
    t = 1;
    while (t--) {
        Enter();
        Process();
    }
}