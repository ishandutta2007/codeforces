#include <iostream>
#include <cmath>
using namespace std;

int x1, y1, x2, y2;

int main(){
    cin >> x1 >> y1 >> x2 >> y2;

    if(y1 == y2){
        int side = abs(x2 - x1);
        cout << x1 << " " << y1 + side << " " << x2 << " " << y2+side << endl;
    }
    else if(x1 == x2){
        int side = abs(y2 - y1);
        cout << x1 + side << " " << y1 << " " << x2 + side << " " << y2 << endl;
    }
    else if(abs(x1 - x2) != abs(y1 - y2)) cout << "-1" << endl;
    else cout << x1 << " " << y2 << " " << x2 << " " << y1 << endl;

    return 0;
}