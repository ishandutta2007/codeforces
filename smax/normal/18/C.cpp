#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, sum = 0, leftSum = 0, ret = 0, a[100000];
    cin >> n;
    for (int i=0; i<n; i++) {
        cin >> a[i];
        sum += a[i];
    }
    
    for (int i=0; i<n-1; i++) {
        leftSum += a[i];
        if (leftSum == sum - leftSum)
            ret++;
    }
    
    cout << ret << endl;
    
    return 0;
}