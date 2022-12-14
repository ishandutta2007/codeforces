#include <bits/stdc++.h>
#define FOR(i,l,r) for(int i=1; i<=r; ++i)
#define REP(i,l,r) for(int i=1; i<r; ++i)
using namespace std;
const int N = 100005;
int t, n, x, odd, even, a, b, f[N];

void Enter() {
}

void Process() {
}

int main()
{
    ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
    cin >> t;
    while (t--) {
        bool ok = false;
        cin >> n >> a >> b;
        if (b == 1) ok = true;
        else if (a == 1) ok = (n%b == 1 || b == 1);
        else {
            long long w = 1;
            while (w <= n) {
                if ((n - w) % b == 0) { ok = true; break; }
                w *= a;
            }
        }
        cout << (ok ? "Yes\n" : "No\n");
    }
}