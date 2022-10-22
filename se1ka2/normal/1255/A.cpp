#include <iostream>
using namespace std;

int main()
{
    int t;
    cin >> t;
    for(int c = 0; c < t; c++){
        int a, b;
        cin >> a >> b;
        int d = abs(a - b);
        if(d % 5 == 0) cout << d / 5 << endl;
        else if(d % 5 == 1 || d % 5 == 2) cout << d / 5 + 1 << endl;
        else cout << d / 5 + 2 << endl;
    }
}