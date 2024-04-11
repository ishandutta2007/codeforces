#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, mx = 0, a[100];
    cin >> n;
    for (int i=0; i<n; i++) {
        cin >> a[i];
        mx = max(mx, a[i]);
    }
    int ret = 0;
    for (int i=0; i<n; i++)
        ret += mx - a[i];
    cout << ret << endl;
    
    return 0;
}