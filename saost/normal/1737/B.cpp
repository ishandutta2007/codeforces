#include <bits/stdc++.h>
#define FOR(i,l,r) for(int i=l; i<=r; ++i)
#define REP(i,l,r) for(int i=l; i<r; ++i)
#define FORD(i,r,l) for(int i=r; i>=l; --i)
#define REPD(i,r,l) for(int i=r-1; i>=l; --i)
using namespace std;
const int N = 100005;
int t, n, m, k, res;
int a[N], b[N], f[N];
long long l, r;

void Enter() {
    cin >> l >> r;
}

long long get(long long x) {
    if (x == 0) return 0;
    long long div = sqrt(x);
    return (div - 1) * 3 + (x - div * div) / div + 1;
}

void Process() {

    cout << get(r) - get(l - 1) << '\n';
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