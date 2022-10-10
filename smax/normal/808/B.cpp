#include <bits/stdc++.h>
using namespace std;
 
int main() {
    int n, k, a[200000];
    cin >> n >> k;
    for (int i=0; i<n; i++)
        cin >> a[i];
    
    long long acc = 0;
    for (int i=0; i<k; i++)
        acc += a[i];
    double avg = acc;
    for (int i=k; i<n; i++) {
        acc += a[i] - a[i-k];
        avg += acc;
    }
    avg /= (n - k + 1);
    
    cout << setprecision(20) << avg << endl;
    
    return 0;
}