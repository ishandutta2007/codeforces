#include <bits/stdc++.h>
using namespace std;
 
int main() {
    int n, maxH = 0, a[100], b[100] = {0};
    cin >> n;
    for (int i=0; i<n; i++) {
        cin >> a[i];
        maxH = max(maxH, a[i]);
    }
    
    sort(a, a+n, greater<int>());
    for (int i=1; i<=maxH; i++) {
        int c = n - 1;
        for (int j=0; j<n; j++) {
            if (a[j] >= i)
                b[c--]++;
            else
                break;
        }
    }
    
    for (int i=0; i<n; i++)
        cout << b[i] << " ";
    cout << endl;
    
    return 0;
}