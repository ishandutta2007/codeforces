//In the name of God
#include <iostream>
using namespace std;
int main(){
    unsigned long long x,y;
    cin >> x >> y;
    if(x < y){
        cout << -1 << endl;
        return 0;
    }
    if((x - y) % 2){
        cout << -1 << endl;
        return 0;
    }
    cout << (x-y)/2 << " " << (x-y)/2 + y << endl;
    return 0;
}