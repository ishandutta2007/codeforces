#include <bits/stdc++.h>
using namespace std;
 
int main() {
    int n, o = 0, a[100];
    cin >> n;
    for (int i=0; i<n; i++) {
        cin >> a[i];
        if (a[i] == 1) {
            o++;
            a[i] = -1;
        } else
            a[i] = 1;
    }
    
    int curMax = a[0], totalMax = a[0];
    for (int i=1; i<n; i++) {
        curMax = max(curMax, 0) + a[i];
        totalMax = max(totalMax, curMax);
    }
    
    cout << o + totalMax << endl;
    
    return 0;
}