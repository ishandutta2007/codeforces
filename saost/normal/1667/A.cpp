#include <bits/stdc++.h>
#define FOR(i,l,r) for(int i=l; i<=r; ++i)
#define REP(i,l,r) for(int i=l; i<r; ++i)
#define FORD(i,r,l) for(int i=r; i>=l; --i)
#define REPD(i,r,l) for(int i=r-1; i>=l; --i)
using namespace std;
const int N = 100005;
int t, n, m, k;
long long res;
long long a[N], b[N], f[N];

void Enter() {
    cin >> n;
    FOR(i, 1, n) cin >> a[i];
}

void Process() {
    res = 9e18;
    FOR(i, 1, n) {
        long long tmp = 0, sum = 0;
        REPD(j, i, 1) {
            long long times = (tmp + a[j]) / a[j];
            sum += times;
            tmp = a[j] * times;
        }
        tmp = 0;
        FOR(j, i+1, n) {
            long long times = (tmp + a[j]) / a[j];
            sum += times;
            tmp = a[j] * times;
        }
        res = min(res, sum);
    }
    cout << res;
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