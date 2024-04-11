#include <iostream>
#include <cstring>
#include <vector>
#include <string>

using namespace std;

int main() {
    int a, b, c;
    cin >> a >> b >> c;
    a = a % b;
    for (int i = 0; i < 1000000; ++i) {
        a *= 10;
        if (c == a / b) {
            cout << i + 1;
            return 0;
        }
        a = a % b;
    }
    cout << -1;
    return 0;
}