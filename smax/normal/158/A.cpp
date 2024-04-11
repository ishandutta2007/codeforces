#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, k, a[50];
    cin >> n >> k;
    for (int i=0; i<n; i++)
        cin >> a[i];
    
    int i = 0;
    while (i < n && a[i] > 0 && a[i] >= a[k-1])
        i++;
    
    cout << i << endl;
    
    return 0;
}