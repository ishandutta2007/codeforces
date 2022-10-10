#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, t, a[30001];
    cin >> n >> t;
    for (int i=1; i<n; i++)
        cin >> a[i];
    
    int pos = 1;
    while (pos < t)
        pos += a[pos];
    if (pos == t)
        cout << "YES" << endl;
    else
        cout << "NO" << endl;
    
    return 0;
}