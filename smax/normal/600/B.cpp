#include <bits/stdc++.h>
using namespace std;
 
int main() {
    int n, m, a[200000];
    cin >> n >> m;
    for (int i=0; i<n; i++)
        cin >> a[i];
    sort(a, a + n);
    for (int i=0; i<m; i++) {
        int b;
        cin >> b;
        cout << upper_bound(a, a + n, b) - begin(a) << endl;
    }
    
    return 0;
}