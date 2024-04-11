#include <iostream>
using namespace std;

int main()
{
    int t;
    cin >> t;
    for(int c = 0; c < t; c++){
        int n, x, y;
        cin >> n >> x >> y;
        if(x + y < n + 1){
            cout << 1 << " " << x + y - 1 << endl;
        }
        else{
            cout << min(n, x + y + 1 - n) << " " << n << endl;
        }
    }
}