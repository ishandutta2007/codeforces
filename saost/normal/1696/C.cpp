#include <bits/stdc++.h>
#define FOR(i,l,r) for(int i=l; i<=r; ++i)
#define REP(i,l,r) for(int i=l; i<r; ++i)
#define FORD(i,r,l) for(int i=r; i>=l; --i)
#define REPD(i,r,l) for(int i=r-1; i>=l; --i)
using namespace std;
const int N = 200005;
int t, n, m, k;
long long val[N], val2[N], cnt[N], cnt2[N];

void Enter() {
    cin >> n >> m;
}

void Process() {
    int r = 0, r2 = 0;
    FOR(i, 1, n) {
        int x; cin >> x;
        int sl = 1;
        while (x % m == 0) x /= m, sl *= m;
        if (r && val[r] == x) cnt[r] += sl;
        else cnt[++r] = sl, val[r] = x;
    }

    cin >> k;
    FOR(i, 1, k) {
        int x; cin >> x;
        int sl = 1;
        while (x % m == 0) x /= m, sl *= m;
        if (r2 && val2[r2] == x) cnt2[r2] += sl;
        else cnt2[++r2] = sl, val2[r2] = x;
    }
    if (r != r2) return void(cout << "No\n");
    FOR(i, 1, r) if (cnt[i] != cnt2[i] || val[i] != val2[i]) return void(cout << "No\n");
    cout << "Yes\n";
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