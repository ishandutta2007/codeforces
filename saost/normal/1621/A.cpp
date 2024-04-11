#include <bits/stdc++.h>
#define FOR(i,l,r) for(int i=l; i<=r; ++i)
#define REP(i,l,r) for(int i=l; i<r; ++i)
#define FORD(i,r,l) for(int i=r; i>=l; --i)
#define REPD(i,r,l) for(int i=r-1; i>=l; --i)
using namespace std;
const int N = 100005;
int t, n, m, k, res;
int a[N], b[N], f[N];

void Enter() {
    cin >> n >> k;
}

void Process() {
    if ((n+1)/2 < k) cout << "-1\n";
    else {
        FOR(i, 1, n) {
            FOR(j, 1, n) {
                if (i%2 && k>0 && i==j) cout << 'R', --k;
                else cout << '.';
            }
            cout << '\n';
        }
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