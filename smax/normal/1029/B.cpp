#include <bits/stdc++.h>
using namespace std;
 
int main() {
    int n, prev, ret = 1, c = 1;
    cin >> n >> prev;
    for (int i=1; i<n; i++) {
        int a;
        cin >> a;
        if (a > 2 * prev) {
            ret = max(ret, c);
            c = 1;
        } else
            c++;
        prev = a;
    }
    ret = max(ret, c);
    cout << ret << endl;
    
    return 0;
}