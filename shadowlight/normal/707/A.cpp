#include <iostream>

using namespace std;

int main() {
    int n, m;
    cin >> n >> m;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            char c;
            cin >> c;
            if (c != 'B' && c != 'W' && c != 'G') {
                cout << "#Color";
                return 0;
            }
        }
    }
    cout << "#Black&White";
}