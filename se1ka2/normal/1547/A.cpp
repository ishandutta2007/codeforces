#include <iostream>
using namespace std;

int main()
{
    int t;
    cin >> t;
    while(t--){
        int x[3], y[3];
        for(int i = 0; i < 3; i++) cin >> x[i] >> y[i];
        if(y[0] == y[1] && y[1] == y[2]){
            for(int i = 0; i < 3; i++) swap(x[i], y[i]);
        }
        if(x[0] == x[1] && x[1] == x[2] && abs(y[0] - y[2]) < abs(y[0] - y[1]) && abs(y[1] - y[2]) < abs(y[0] - y[1])){
            cout << abs(y[1] - y[0]) + 2 << endl;
        }
        else cout << abs(y[1] - y[0]) + abs(x[1] - x[0]) << endl;
    }
}