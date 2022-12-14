#include <iostream>
using namespace std;
int t, n, f[100005];
long long k;

void Solve() {
    if (n < 63 && (1ll<<(n-1)) < k) { cout << "-1\n"; return; }
    int p = max(1, n - 62);
    long long power = (1ll<<(n-p));
    for(int i=1; i<p; ++i) f[i] = i;
    for(int i=p; i<=n; ++i) {
        power >>= 1;
        int c = 0;
        for(; power < k && k>1; power >>= 1) {
            ++c;
            k -= power;
        }
        for(int j=0; j<=c; ++j) f[i+j] = i+c-j;
        i += c;
    }
    for(int i=1; i<=n; ++i) cout << f[i] << ' ';
    cout << '\n';
}

int main()
{
    ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
    cin >> t;
    while (t--) {
        cin >> n >> k;
        Solve();
    }
}