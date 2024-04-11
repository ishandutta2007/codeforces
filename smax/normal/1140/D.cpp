#include <bits/stdc++.h>
using namespace std;
 
int main() {
    int n, ret = 0;
    cin >> n;
    for (int i=2; i<n; i++)
        ret += i * (i+1);
    cout << ret << endl;
    
    return 0;
}