#include <bits/stdc++.h>
using namespace std;
 
int main() {
    int n, m, f[50];
    cin >> n >> m;
    for (int i=0; i<m; i++)
        cin >> f[i];
    
    sort(f, f+m);
    int ret = INT_MAX;
    for (int i=n-1; i<m; i++)
        ret = min(ret, f[i]-f[i-n+1]);
    
    cout << ret << endl;
    
    return 0;
}