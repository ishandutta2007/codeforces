#include <iostream>

using namespace std;

int main(){
    int n;
    cin >> n;
    if (n == 1) {
        cout << "1\n1 1" << endl;
        return 0;
    }

    int m = (n/2) + 1;
    cout << m << "\n";
    int r = 1, c = 1;
    while (n-- > 0) {
        if (c > m) {
            c = m;
            r = 2;
        }
        cout << r << " " << c << "\n";
        if (r == 1) ++c;
        else ++r;
    }

    return 0;
}