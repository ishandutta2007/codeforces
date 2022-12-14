//In the name of God
#include <iostream>
using namespace std;
int main(){
    int n;
    cin >> n;
    int x,y;
    cin >> x >> y;
    for(int a = 0; a < 2;a++){
        for(int b = 0; b < 2;b++){
            if(x == n/2 + a && y == n/2 + b){
                cout << "NO" << endl;
                return 0;
            }
        }
    }
    cout << "YES" << endl;
    return 0;
}