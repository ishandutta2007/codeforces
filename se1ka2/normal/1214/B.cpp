#include <iostream>
using namespace std;

int main()
{
    int b, g, n;
    cin >> b >> g >> n;
    if(b < g) swap(b, g);
    cout << n + 1 - (max(0, n - b) + max(0, n - g)) << endl;
}