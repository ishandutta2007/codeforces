#include <iostream>
using namespace std;

int main()
{
    int a, b;
    cin >> a >> b;
    if(a == b) cout << a << 0 << " " << b << 1 << endl;
    else if(a + 1 == b) cout << a << " " << b << endl;
    else if(a == 9 && b == 1) cout << "9 10" << endl;
    else cout << -1 << endl;
}