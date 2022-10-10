#include <bits/stdc++.h>
using namespace std;
 
int main() {
    int x;
    cin >> x;
    
    cout << (x % 5 == 0 ? x / 5 : x / 5 + 1) << endl;
    
    return 0;
}