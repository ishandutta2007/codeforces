#include <iostream>
using namespace std;
const int N = 5005;
long long n, res, a[N], b[N], f[N][N];

int main()
{
    ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
    cin >> n;
    for(int i=1; i<=n; ++i) cin >> a[i];
    for(int i=1; i<=n; ++i) cin >> b[i];
    for(int i=1; i<=n; ++i) res += a[i] * b[i];
    for(int i=1; i<=n; ++i) f[i][i] = f[i][i-1] = res;

    for(int i=1; i<n; ++i) for(int j=1; i+j<=n; ++j) {
        int w = i+j;
        f[j][w] = f[j+1][w-1] - a[j]*b[j] - a[w]*b[w] + a[j]*b[w] + a[w]*b[j];
        res = max(res, f[j][w]);
    }
    cout << res;
}