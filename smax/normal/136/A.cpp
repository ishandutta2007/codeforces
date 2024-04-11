#include <bits/stdc++.h>
using namespace std;
 
int main() {
    int n, a[101], b[101];
    cin >> n;
    for (int i=1; i<=n; i++) {
        cin >> a[i];
        b[a[i]] = i;
    }
    
    for (int i=1; i<=n; i++)
        cout << b[i] << " ";
    cout << endl;
    
    return 0;
}