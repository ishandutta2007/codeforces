#include <iostream>

using namespace std;

int main() {
    int n;
    cin >> n;
    bool a;
    char ch;
    cin >> ch;
    a = ch == 'F';
    int res = 0;
    for (int i = 1; i < n; ++i) {
        cin >> ch;
        bool b = ch == 'F';
        if (a != b) {
            if (a) {
                --res;
            } else {
                ++res;
            }
        }
        a = b;
    }
    if (res > 0) {
        cout << "YES";
    } else {
        cout << "NO";
    }
    return 0;
}