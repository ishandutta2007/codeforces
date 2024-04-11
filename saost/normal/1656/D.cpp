#include <bits/stdc++.h>
#define FOR(i,l,r) for(int i=l; i<=r; ++i)
#define REP(i,l,r) for(int i=l; i<r; ++i)
#define FORD(i,r,l) for(int i=r; i>=l; --i)
#define REPD(i,r,l) for(int i=r-1; i>=l; --i)
using namespace std;
const int N = 200005;
long long t, n;
int a[N], b[N], f[N];

void Enter() {
    cin >> n;
}

void Process() {
    long long aa = n, tmp = 2;
    while (n%2 == 0) tmp <<= 1, n /= 2;
    if (n == 1) cout << "-1\n";
    else {
        cout << min(n, tmp) << '\n';
    }
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