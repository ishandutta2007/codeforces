#include <iostream>

using namespace std;

int main(){
    int t; cin >> t;
    while (t--) {
        int n; cin >> n;
        string x, y; cin >> x >> y;
        int a = 0, b = 0 ;
        for (int i = 0; i < n; i++) {
            if (x[i] > y[i]) {
                ++a;
            } else if (x[i] < y[i]) {
                ++b;
            }
        }
        string r;
        if (a == b) r = "EQUAL";
        else if (a > b) r = "RED";
        else r = "BLUE";
        cout << r << "\n";
    }

    return 0;
}