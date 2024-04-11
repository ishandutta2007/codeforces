#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, ret = 0, c = 0;
    cin >> n;
    for (int i=0; i<n; i++) {
        int a, b;
        cin >> a >> b;
        c += b - a;
        ret = max(ret, c);
    }
    
    cout << ret << endl;
    
    return 0;
}