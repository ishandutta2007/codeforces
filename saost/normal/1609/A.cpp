#include <bits/stdc++.h>
using namespace std;
const long long N = 100005;
int t, n, k, a[N];
long long x, sum, res, dem;

int main()
{
    ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
    cin >> t;
    while (t--) {
        sum = res = dem = 0;
        cin >> n;
        for(int i=1; i<=n; ++i) {
            cin >> x;
            while (x%2==0) x/=2, ++dem;
            res = max(res, x);
            sum += x;
        }
        sum -= res;
        while (dem--) res *= 2;
        cout << sum + res << '\n';
    }
}