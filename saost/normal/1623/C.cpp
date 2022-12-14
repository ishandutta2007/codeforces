#include <bits/stdc++.h>
#define FOR(i,l,r) for(int i=l; i<=r; ++i)
#define REP(i,l,r) for(int i=l; i<r; ++i)
#define FORD(i,r,l) for(int i=r; i>=l; --i)
#define REPD(i,r,l) for(int i=r-1; i>=l; --i)
using namespace std;
const int N = 200005;
int t, n, m, k, res, res2, xa, xb, ya, yb;
int a[N];
int b[N], ans[N];

void Enter() {
    cin >> n;
    FOR(i, 1, n) cin >> a[i];
}

bool check(int x) {
    FOR(i, 1, n) b[i] = 0;
    FORD(i, n, 3) {
        if (a[i] + b[i] < x) return false;
        int sl = (a[i] - max(0, x - b[i])) / 3;
        b[i - 2] += sl * 2;
        b[i - 1] += sl;
    }
    return a[1] + b[1] >= x && a[2] + b[2] >= x;
}

void Process() {
    int l = 0, r = 1e9, mid;
    while (l < r) {
        mid = (l+r+1) / 2;
        if (check(mid)) l = mid; else r = mid - 1;
    }
    cout << l << '\n';
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