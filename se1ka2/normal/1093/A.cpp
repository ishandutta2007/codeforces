#include <iostream>
using namespace std;

int main()
{
    int t;
    cin >> t;
    for(int c = 0; c < t; c++){
        int x;
        cin >> x;
        if(x % 2) x--;
        cout << x / 2 << endl;
    }
}