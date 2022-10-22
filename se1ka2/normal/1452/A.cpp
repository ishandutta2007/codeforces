#include <iostream>
using namespace std;

int main()
{
    int t;
    cin >> t;
    while(t--){
        int x, y;
        cin >> x >> y;
        if(x == y) cout << x + y << endl;
        else cout << max(x, y) * 2 - 1 << endl;
    }
}