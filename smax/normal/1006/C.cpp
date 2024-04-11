#include <bits/stdc++.h>
using namespace std;
 
int main() {
    int n, d[200000];
    cin >> n;
    for (int i=0; i<n; i++)
        cin >> d[i];
    
    int r = n - 1;
    long long lsum = 0, rsum = 0, ret = 0;
    for (int l=0; l<n; l++) {
        lsum += d[l];
        while (rsum < lsum && l < r)
            rsum += d[r--];
        if (lsum == rsum)
            ret = lsum;
    }
    
    cout << ret << endl;
    
    return 0;
}