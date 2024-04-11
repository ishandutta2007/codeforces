#include <iostream>
using namespace std;

int main()
{
    int t;
    cin >> t;
    for(int count = 0; count < t; count++){
        int a, b, c;
        cin >> a >> b >> c;
        if(c > b * 2) cout << b * 3 << endl;
        else if(b - c / 2 > a * 2) cout << (c / 2) * 3 + a * 3 << endl;
        else cout << (c / 2) * 3 + ((b - c / 2) / 2) * 3 << endl;
    }
}