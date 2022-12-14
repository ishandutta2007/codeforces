#include <bits/stdc++.h>
using namespace std;
const int N = 200005;
int n, n1, n2;
long long a[N], sum1, sum2;

int main()
{
    ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
    cin >> n >> n1 >> n2;
    if (n1 > n2) swap(n1, n2);
    for(int i=1; i<=n; ++i) cin >> a[i];
    sort(a+1, a+n+1);
    for(int i=n; i>=n-n1+1; --i) sum1 += a[i];
    for(int i=n-n1; i>=n-n1-n2+1; --i) sum2 += a[i];
    cout << setprecision(8) << fixed << (long double) sum1 / n1 + (long double) sum2 / n2;
}