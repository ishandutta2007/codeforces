#include <bits/stdc++.h>
using namespace std;

typedef long long LL;

const int SZ = 200005;
LL n, m, a[SZ], sum[SZ];

int main() {
    cin>>n>>m;
    for (int i = 0; i < n; i++) cin>>a[i];
    sort(a, a+n);
    LL r = 0;
    for (int i = 0; i < n; i++)
        cout << (r += sum[i%m] += a[i]) << "\n";    
    return 0;
}