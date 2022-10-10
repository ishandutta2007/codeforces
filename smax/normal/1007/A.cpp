#include <bits/stdc++.h>
using namespace std;
 
int main() {
    int n, a[100000];
    cin >> n;
    for (int i=0; i<n; i++)
        cin >> a[i];
    
    sort(a, a + n);
    int r = 0, ret = 0;
    for (int l=0; l<n; l++) {
        while (r < n && a[l] >= a[r])
            r++;
        if (r < n)
            ret++;
        r++;
    }
    
    cout << ret << endl;
    
    return 0;
}