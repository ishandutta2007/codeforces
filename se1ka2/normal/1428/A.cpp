#include <iostream>
using namespace std;

int main()
{
    int t;
    cin >> t;
    while(t--){
        int x1, y1, x2, y2;
        cin >> x1 >> y1 >> x2 >> y2;
        if(x1 == x2 || y1 == y2) cout << abs(x1 - x2) + abs(y1 - y2) << endl;
        else cout << abs(x1 - x2) + abs(y1 - y2) + 2 << endl;
    }
}