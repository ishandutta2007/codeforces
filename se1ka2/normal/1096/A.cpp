#include <iostream>
using namespace std;

int main()
{
    int t;
    cin >> t;
    for(int c = 0; c < t; c++){
        int l, r;
        cin >> l >> r;
        if(r % 2) r--;
        cout << r / 2 << " " << r << endl;
    }
}