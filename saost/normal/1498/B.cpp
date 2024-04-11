#include <iostream>
#include <cmath>
#define getBIT(x,i) ((x>>i)&1)
using namespace std;
long long t, n, m, res, c[35], d[35];

int main()
{
    ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
    cin >> t;
    while (t--) {
        res = 0;
        cin >> n >> m;
        for(int i=0; i<=30; ++i) c[i] = d[i] = 0;
        for(int i=1; i<=n; ++i) {
            int x;
            cin >> x;
            int v = log2(x);
            c[v]++;
        }
        for(int i=30; i>=0; --i) {
            d[i] += d[i+1]*2;
            while (c[i]--) {
                if (!d[i]) {
                    ++res;
                    d[i] = m / (1<<i);
                    for(int j=i-1; j>=0; --j) d[j] += getBIT(m, j);
                }
                d[i]--;
            }
        }
        cout << res << '\n';
    }
}