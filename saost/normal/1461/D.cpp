#include <bits/stdc++.h>
#define FOR(i, l, r) for(int i=l; i<=r; i++)
#define FORD(i, r, l) for(int i=r; i>=l; i--)
#define REP(i, l, r) for(int i=l; i<r; i++)
using namespace std;
int t, n, m, cnt, a[100005];
long long x, f[100005], d[100005];

void Solve(int l, int r) {
    d[++cnt] = f[r] - f[l-1];
    if (a[l] == a[r]) return;
    int val = (a[l] + a[r]) / 2;
    int pos = upper_bound(a + l, a + r + 1, val) - a; pos--;
    Solve(l, pos);
    Solve(pos+1, r);
}

int main()
{
    ios_base::sync_with_stdio(false);cin.tie(NULL);
    cin >> t;
    while (t--) {
        cin>>n>>m; cnt = 0;
        FOR(i, 1, n) cin>>a[i];
        sort(a+1, a+n+1);
        FOR(i, 1, n) f[i] = f[i-1] + a[i];
        Solve(1, n);
        sort(d + 1, d + cnt + 1); d[cnt+1] = 0;
        while (m--) {
            cin>>x;
            int pos = lower_bound(d + 1, d + cnt + 1, x) - d;
            if (d[pos] == x) cout << "Yes\n"; else cout << "No\n";
        }
    }
}