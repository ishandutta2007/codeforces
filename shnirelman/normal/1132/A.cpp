#include <bits/stdc++.h>

using namespace std;

int main() {
    int a, b, c, d;
    cin >> a >> b >> c >> d;
    
    if(a != d) 
        cout << 0;
    else if(a == 0 && c != 0)
        cout << 0 ;
    else 
        cout << 1;

}