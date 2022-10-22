#include <iostream>

using namespace std;

int main() {
    int n;
    cin >> n;
    int win = -1;
    int a;
    cin >> a;
    if (a % 2 == 0) win = 1; else win = 2;
    cout << win << endl;
    for (int i = 1; i < n; i++) {
        cin >> a;
        if (a % 2 == 0) {
            win += 1;
            if (win == 3) win = 1;
        }
        cout << win << endl;
    }
}