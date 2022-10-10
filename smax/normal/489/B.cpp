#include <bits/stdc++.h>
using namespace std;
 
int main() {
    int n, a[100], m, b[100];
    cin >> n;
    for (int i=0; i<n; i++)
        cin >> a[i];
    sort(a, a + n);
    cin >> m;
    for (int i=0; i<m; i++)
        cin >> b[i];
    sort(b, b + m);
    
    int j = 0, ret = 0;
    for (int i=0; i<n; i++) {
        while (j < m && a[i]-b[j] > 1)
            j++;
        if (j == m)
            break;
        else if (abs(a[i]-b[j]) <= 1) {
            ret++;
            j++;
        }
    }
    
    cout << ret << endl;
    
    return 0;
}