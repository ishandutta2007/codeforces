#include <bits/stdc++.h>
using namespace std;
int t, n, d, c[105];
char a[105];

void dp(int x) {
    if (d == 0) return;
    if (x > n) {
        --d;
        for(int i=1; i<=n*2; ++i) cout << a[i];
        cout << '\n';
        return;
    }
    c[x] = c[x-1] + 1; a[x] = '('; a[n*2-x+1] = ')'; dp(x+1);
    if (c[x] == 0) return;
    c[x] = c[x-1] - 1; a[x] = ')'; a[n*2-x+1] = '('; dp(x+1);
}

int main()
{
    ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
    cin >> t;
    while (t--) {
        cin >> n; d = n;
        dp(1);
    }
}