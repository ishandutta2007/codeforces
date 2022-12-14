#include <bits/stdc++.h>
#define FOR(i, l, r) for(int i=l; i<=r; i++)
#define REP(i, l, r) for(int i=l; i<r; i++)
#define FORD(i, r, l) for(int i=r; i>=l; i--)
#define REPD(i, r, l) for(int i=r-1; i>=l; i--)
using namespace std;
long long n, t, k, p[105];
void ReadInt(long long &x) {
    char c = getchar();
    while (!isdigit(c) && c != '-') c = getchar();
    long long deg = 1;
    if (c == '-') deg = -1, c = getchar();
    x = 0;
    while (isdigit(c)) x = (x<<3) + (x<<1) + c - '0', c = getchar();
    x *= deg;
}

void Solve() {
    long long res = 0, sum = p[1];
    for(int i=2; i<=n; i++) {
        if (k*sum < p[i]*100) {
            long long d = (p[i]*100+k-1)/k;
            res += d - sum;
            sum = d;
        }
        sum += p[i];
    }
    cout << res << '\n';
}

int main()
{
    ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
    cin >> t;
    while (t--) {
        cin >> n >> k;
        for(int i=1; i<=n; i++) cin >> p[i];
        Solve();
    }
}