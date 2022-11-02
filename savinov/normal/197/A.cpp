#include <iostream>
#include <algorithm>

using namespace std;

int main()
{
    int a,b,r;
    cin >> a  >> b >> r;
    if (2*r<=min(a,b)) cout << "First\n"; else cout << "Second\n";
    return 0;
}