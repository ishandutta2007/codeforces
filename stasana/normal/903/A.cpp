#include <iostream>
#include <cstring>
#include <vector>
#include <string>

using namespace std;

typedef long long ll;

bool f(int x) {
    for (int i = 0; i * 7 <= x; ++i) {
        if ((x - i * 7) % 3 == 0) {
            return true;
        }
    }
    return false;
}

int main() {
    int n;
    cin >> n;
    for (int i = 0; i < n; ++i) {
        int x;
        cin >> x;
        if (f(x)) {
            cout << "YES" << endl;
        } else {
            cout << "NO" << endl;
        }
    }
    return 0;
}