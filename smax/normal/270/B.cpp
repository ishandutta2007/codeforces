#include <bits/stdc++.h>
using namespace std;
 
int main() {
    int n, a[100000];
    cin >> n;
    for (int i=0; i<n; i++)
        cin >> a[i];
    int ret = n - 1;
    while (ret > 0 && a[ret-1] < a[ret])
        ret--;
    cout << ret << endl;
    
    return 0;
}