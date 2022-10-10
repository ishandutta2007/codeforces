#include <bits/stdc++.h>
using namespace std;
 
int main() {
    int n, k, ret = 0, b[500];
    cin >> n >> k >> b[0];
    for (int i=1; i<n; i++) {
        int a;
        cin >> a;
        b[i] = a + max(0, k - b[i-1] - a);
        ret += max(0, k - b[i-1] - a);
    }
    cout << ret << endl;
    for (int i=0; i<n; i++)
        cout << b[i] << " ";
    cout << endl;
    
    return 0;
}