#include <iostream>
using namespace std;

int main()
{
    int t;
    cin >> t;
    for(int c = 0; c < t; c++){
        int x, y;
        cin >> x >> y;
        if(x >= 4){
            cout << "YES" << endl;
        }
        if(x == 2 || x == 3){
            if(y <= 3) cout << "YES" << endl;
            else cout << "NO" << endl;
        }
        if(x == 1){
            if(y <= 1) cout << "YES" << endl;
            else cout << "NO" << endl;
        }
    }
}