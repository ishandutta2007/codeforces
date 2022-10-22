#include <iostream>

using namespace std;

int main()
{
    int c[10] = {2, 7, 2, 3, 3, 4, 2, 5, 1, 2};
    int a;
    cin >> a;

    int b = a % 10;
    a /= 10;

    cout << c[a] * c[b] << endl;
    return 0;
}