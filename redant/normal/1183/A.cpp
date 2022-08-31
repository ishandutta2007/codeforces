#include <iostream>

using namespace std;

bool ok(int n) {
    int s = 0;
    while (n) {
        s += n % 10;
        n /= 10;
    }
    return s % 4 == 0;
}

int main(){
    int n; cin >> n;
    while (true) {
        if (ok(n)) {
            cout << n << endl;
            break;
        }
        ++n;
    }

    return 0;
}