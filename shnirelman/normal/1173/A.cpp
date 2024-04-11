#include <bits/stdc++.h>

using namespace std;

int main(){
    int x, y, z;
    cin >> x >> y >> z;

    x -= y;

    if(x == 0){
        if(z == 0)cout << 0;
        else cout << "?";
    }
    else if(x > 0){
        if(z >= x)cout << "?";
        else cout << '+';
    }
    else{
        if(z >= -x)cout << "?";
        else cout << '-';
    }

}