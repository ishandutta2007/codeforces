#include <iostream>
using namespace std;
int x;
int main() {
    cin >> x;
    if (x % 10 <= 5) {
        x -= x % 10;
    } else {
        x += 10 - x % 10;
    }
    cout << x << endl;
}