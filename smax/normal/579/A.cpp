#include <bits/stdc++.h>
using namespace std;
 
int main() {
    int x;
    cin >> x;
    
    int ret = 0;
    bitset<30> b(x);
    for (int i=0; i<30; i++)
        ret += b[i];
    
    cout << ret << endl;
    
    return 0;
}