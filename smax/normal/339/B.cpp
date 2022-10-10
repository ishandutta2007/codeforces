#include <bits/stdc++.h>
using namespace std;
 
int main() {
    int n, m, pos = 1;
    cin >> n >> m;
    long long time = 0;
    for (int i=0; i<m; i++) {
        int a;
        cin >> a;
        time += (pos <= a ? a - pos : a + n - pos);
        pos += min(a - pos, a + n - pos);
    }
    
    cout << time << endl;
    
    return 0;
}