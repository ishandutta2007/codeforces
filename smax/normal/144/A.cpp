#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, mx = 0, mxpos, mn = INT_MAX, mnpos;
    cin >> n;
    for (int i=0; i<n; i++) {
        int a;
        cin >> a;
        if (a > mx) {
            mx = a;
            mxpos = i;
        }
        if (a <= mn) {
            mn = a;
            mnpos = i;
        }
    }
    
    if (mxpos > mnpos)
        cout << mxpos + n - mnpos - 2 << endl;
    else
        cout << mxpos + n - mnpos - 1 << endl;
    
    return 0;
}