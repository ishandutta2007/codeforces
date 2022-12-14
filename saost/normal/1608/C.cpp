#include <bits/stdc++.h>
#define FOR(i,l,r) for(int i=l; i<=r; ++i)
#define REP(i,l,r) for(int i=l; i<r; ++i)
#define FORD(i,r,l) for(int i=r; i>=l; --i)
#define REPD(i,r,l) for(int i=r-1; i>=l; --i)
using namespace std;
const int N = 100005;
int t, n, win[N], p[N];
pair<int,int> a[N];

void Enter() {
    cin >> n;
    FOR(i, 1, n) cin >> a[i].first;
    FOR(i, 1, n) cin >> a[i].second;
}

void Process() {
    FOR(i, 1, n) p[i] = i, win[i] = 0;
    sort(p+1, p+n+1, [] (int x, int y) { return a[x] > a[y]; });
    win[p[1]] = 1;
    int mx = a[p[1]].second;
    FOR(i, 2, n) {
        int j = i;
        while (j <= n && a[p[j]].second < mx) ++j;
        if (j <= n) {
            while (i <= j) mx = min(mx, a[p[i]].second), win[p[i++]] = true;
        }
        i = j;
    }
    FOR(i, 1, n) cout << win[i];
    cout << '\n';
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