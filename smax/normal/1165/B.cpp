#include <bits/stdc++.h>
using namespace std;
 
int main() {
    int n, a[200000];
    cin >> n;
    for (int i=0; i<n; i++)
        cin >> a[i];
    
    sort(a, a + n);
    int ret = 0, index = 0;
    while (index < n) {
        if (a[index] > ret)
            ret++;
        index++;
    }
    
    cout << ret << endl;
    
    return 0;
}