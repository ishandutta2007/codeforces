#include <iostream>
#include <cstdlib>
#include <iostream>

using namespace std;

int main()
{
    int a[3], b[3];
    for (int i=  0; i < 3; i++)
        cin >> a[i];
    for (int i=  0; i < 3; i++)
        cin >> b[i];
    for (int i=  0; i < 3; i++)
        if (a[i] == b[i]) {cout << "YES"; return 0;}
    cout << "NO";

    return 0;
}