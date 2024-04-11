#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, ret = 0;
    cin >> n;
    while (n > 0) {
        int j = n, mx = 0;
        while (j > 0) {
            mx = max(mx, j % 10);
            j /= 10;
        }
        n -= mx;
        ret++;
    }
    
    cout << ret << endl;
    
    return 0;
}