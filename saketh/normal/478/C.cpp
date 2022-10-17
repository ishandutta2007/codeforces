#include <iostream>
#include <algorithm>
using namespace std;

long long c[3];

int main(){
    cin >> c[0] >> c[1] >> c[2];
    sort(c, c+3);

    long long can = (c[0] + c[1]) * 2;
    if( can >= c[2] )
        cout << (c[0] + c[1] + c[2]) / 3 << endl;
    else cout << can/2 << endl;    
}