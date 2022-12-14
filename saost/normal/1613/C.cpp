#include <bits/stdc++.h>
#define FOR(i,l,r) for(int i=l; i<=r; ++i)
#define REP(i,l,r) for(int i=l; i<r; ++i)
#define FORD(i,r,l) for(int i=r; i>=l; --i)
#define REPD(i,r,l) for(int i=r-1; i>=l; --i)
using namespace std;
const int N = 100005;
int t, n, a[N];
long long h;

bool check(long long x) {
    long long sum = 0, d = 0;
    for(int i=1; i<=n; ++i) {
        d = max(d, 1LL * a[i]);
        sum += a[i] + x - d;
        d = a[i] + x;
    }
    return sum >= h;
}

int main()
{
    ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
    cin >> t;
    while (t--) {
        cin >> n >> h;
        for(int i=1; i<=n; ++i) cin >> a[i];
        long long l = 1, r = h, mid;
        while (l < r) {
            mid = (l+r) / 2;
            if (check(mid)) r = mid; else l = mid + 1;
        }
        cout << l << '\n';
    }
}