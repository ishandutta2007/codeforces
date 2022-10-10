#include <bits/stdc++.h>
using namespace std;
 
int main() {
    int n, m, d, a[10000], s[10001];
    cin >> n >> m >> d;
    for (int i=0; i<n*m; i++)
        cin >> a[i];
    
    sort(a, a + n * m);
    for (int i=1; i<n*m; i++)
        if ((a[i] - a[i-1]) % d != 0) {
            cout << -1 << endl;
            return 0;
        }
    
    s[0] = 0;
    for (int i=0; i<n*m; i++)
        s[i+1] = s[i] + a[i];
    
    int ret = INT_MAX;
    for (int i=0; i<n*m; i++)
        ret = min(ret, i * a[i] - 2 * s[i] + s[n*m] - (n * m - i) * a[i]);
    
    cout << ret / d << endl;
    
    return 0;
}