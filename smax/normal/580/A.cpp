#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, a[100000];
    cin >> n;
    for (int i=0; i<n; i++)
        cin >> a[i];
    
    int ret = 0, c = 1;
    for (int i=1; i<n; i++) {
        if (a[i] < a[i-1]) {
            ret = max(ret, c);
            c = 1;
        } else
            c++;
    }
    ret = max(ret, c);
    
    cout << ret << endl;
    
    return 0;
}