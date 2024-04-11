#include <bits/stdc++.h>
using namespace std;
 
int main() {
    int n, k, sum = 0, h[150000];
    cin >> n >> k;
    for (int i=0; i<k; i++) {
        cin >> h[i];
        sum += h[i];
    }
    int ret = 1, minSum = sum;
    for (int i=k; i<n; i++) {
        cin >> h[i];
        sum += h[i] - h[i-k];
        if (sum < minSum) {
            minSum = sum;
            ret = i - k + 2;
        }
    }
    cout << ret << endl;
    
    return 0;
}