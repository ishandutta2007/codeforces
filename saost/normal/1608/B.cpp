#include <bits/stdc++.h>
#define FOR(i,l,r) for(int i=l; i<=r; ++i)
#define REP(i,l,r) for(int i=l; i<r; ++i)
#define FORD(i,r,l) for(int i=r; i>=l; --i)
#define REPD(i,r,l) for(int i=r-1; i>=l; --i)
using namespace std;
const int N = 100005;
int t, n, a, b;

void Enter() {
    cin >> n >> a >> b;
}

void Process() {
    if (abs(a - b) > 1 || a + b > n - 2) { cout << "-1\n"; return; }
    int l = 1, r = n , pa = a, pb = b;
    if (a >= b) {
        while (a) {
            cout << l++ << ' ', --a;
            if (b) cout << r-- << ' ', --b;
        }
        while (l <= r) {
            if (pa > pb) cout << r-- << ' ';
            else cout << l++ << ' ';
        }
    }
    else {
        while (b) {
            cout << r-- << ' ', --b;
            if (a) cout << l++ << ' ', --a;
        }
        while (l <= r) cout << l++ << ' ';
    }
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