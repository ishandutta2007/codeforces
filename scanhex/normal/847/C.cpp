#include <iostream>
#include <vector>

using namespace std;

int main() {
    int n;
    long long k;
    cin >> n >> k;
    if (1LL * n * (n - 1) / 2 < k) {
        cout << "Impossible" << endl;
        return 0;
    }
    int x = 1;
    while (1LL * x * (x - 1) / 2 <= k) {
        x++;
    }
    x--;
    int y = 1LL * x * (x - 1) / 2 + x - k;
    string s = "";
    for (int i = 0; i < x; i++) {
        s.push_back('(');
    }
    for (int i = 0; i < y; i++) {
        s.push_back(')');
    }
    if (y != x) {
        s.push_back('(');
        s.push_back(')');
    }
    for (int i = 0; i < x - y; i++) {
        s.push_back(')');
    }

    while (s.length() < 2 * n) {
        s.push_back('(');
        s.push_back(')');
    }

    cout << s << endl;


    return 0;
}