#include <iostream>

using namespace std;

int
main()
{
    int n1, k1, n2, k2;
    cin >> n1 >> n2 >> k1 >> k2;
    if (n1 > n2) {
        cout << "First\n";
    } else {
        cout << "Second\n";
    }
    return 0;
}