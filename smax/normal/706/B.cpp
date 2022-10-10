#include <bits/stdc++.h>
using namespace std;
 
int main() {
    int n, q, x[100000];
    cin >> n;
    for (int i=0; i<n; i++)
        cin >> x[i];
    sort(x, x + n);
    cin >> q;
    for (int i=0; i<q; i++) {
        int m;
        cin >> m;
        cout << (upper_bound(x, x + n, m) - begin(x)) << endl;
    }
    
    return 0;
}