#include <iostream>

using namespace std;

int main() {
    int num;
    char c1;
    cin >> c1 >> num;
    int c = c1 - 'a' + 1;
    if (num == 1 || num == 8) {
        if (c == 1 || c == 8) {
            cout << 3;
        } else {
            cout << 5;
        }
    } else if (c == 1 || c == 8) {
        cout << 5;
    } else {
        cout << 8;
    }
}