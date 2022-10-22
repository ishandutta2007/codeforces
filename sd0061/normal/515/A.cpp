#include <iostream>
using namespace std;
int main() {
    int a , b , s;
    cin >> a >> b >> s;
    if (a < 0) a = -a;
    if (b < 0) b = -b;
    if (a + b > s || ((s ^ (a + b)) & 1))
        cout << "No";
    else
        cout << "Yes";
    return 0;
}