#include <bits/stdc++.h>
using namespace std;
 
int main() {
    int n, l, a[1000];
    cin >> n >> l;
    for (int i=0; i<n; i++)
        cin >> a[i];
    
    sort(a, a + n);
    int ret = max(a[0], l - a[n-1]) * 2;
    for (int i=0; i<n-1; i++)
        ret = max(ret, a[i+1]-a[i]);
    
    cout.precision(20);
    cout << fixed << ret / 2.0 << endl;
    
    return 0;
}