#include <algorithm>
#include <iostream>
using namespace std;

int main()
{
    int t;
    cin >> t;
    for(int c = 0; c < t; c++){
        int a[3];
        cin >> a[0] >> a[1] >> a[2];
        sort(a, a + 3);
        if(a[0] + a[1] >= a[2]) cout << (a[0] + a[1] + a[2]) / 2 << endl;
        else cout << a[0] + a[1] << endl;
    }
}