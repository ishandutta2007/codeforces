#include <iostream>
#include <cmath>

using namespace std;

int main(){
    int x1, y1, x2, y2, x, y;
    cin >> x1 >> y1 >> x2 >> y2 >> x >> y;
    if(abs(x1 - x2) %  x != 0 ||  abs(y1 - y2) % y != 0){
        cout << "NO";
        return 0;
    }
    if((abs(x1 - x2) /  x + abs(y1 - y2) / y) % 2 == 1)
        cout << "NO";
    else
        cout << "YES";
    return 0;
}