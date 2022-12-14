#include <bits/stdc++.h>
#define FOR(i,l,r) for(int i=(l); i<=(r); ++i)
#define REP(i,l,r) for(int i=(l); i<(r); ++i)
#define FORD(i,r,l) for(int i=(r); i>=(l); --i)
#define REPD(i,r,l) for(int i=(r)-1; i>=(l); --i)
using namespace std;
const int N = 1e5 + 5;
int n, res, a[N], f[N];

void Enter() {
    cin >> n;
}

void Process() {
    long long sum = 0;
    bool ok = true, isend = false;
    FOR(i, 1, n) {
        int x; cin >> x; sum += x;
        if (sum < 0 || isend && sum) ok = false;
        if (sum == 0) isend = true;
    }
    if (sum) ok = false;
    cout << (ok ? "YES\n" : "NO\n");
}

int main()
{
    #define file ""
    ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
    if (fopen(file".inp","r")) {
        freopen(file".inp","r",stdin);
        freopen(file".out","w",stdout);
    }
    int t; cin >> t;
    while (t--) {
        Enter();
        Process();
    }
}