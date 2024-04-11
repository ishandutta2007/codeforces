#include <bits/stdc++.h>
using namespace std;
 
int main() {
    int n, a[100], sum = 0;
    cin >> n;
    for (int i=0; i<n; i++) {
        cin >> a[i];
        sum += a[i];
    }
    
    sort(a, a + n, greater<int>());
    int partialSum = 0, i = 0;
    while (partialSum <= sum - partialSum)
        partialSum += a[i++];
    
    cout << i << endl;
    
    return 0;
}