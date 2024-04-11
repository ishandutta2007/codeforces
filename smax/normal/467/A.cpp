#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, ret = 0;
    cin >> n;
    for (int i=0; i<n; i++) {
        int p, q;
        cin >> p >> q;
        if (q - p >= 2)
            ret++;
    }
    cout << ret << endl;
    
    return 0;
}