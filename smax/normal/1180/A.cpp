#include <bits/stdc++.h>
using namespace std;
 
int main() {
    int n, ret = 1;
    cin >> n;
    for (int i=1; i<n; i++)
        ret += 4 * i;
    cout << ret << endl;
    
    return 0;
}