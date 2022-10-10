#include <bits/stdc++.h>
using namespace std;
 
int main() {
    int k, n, w;
    cin >> k >> n >> w;
    cout << (w * (w + 1) / 2 * k - n > 0 ? w * (w + 1) / 2 * k - n : 0) << endl;
    
    return 0;
}