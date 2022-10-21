#include <bits/stdc++.h>
using namespace std;

int a, b, c, d;

int main() {
    cin >> a >> b >> c >> d;
    while(a > 1) {
        if(a % 2 == 0) {
            if(b % 2 == 0) a /= 2, b /= 2, cout << "/1\n";
            else b++, c++, cout << "+2\n";
        }
        else {
            a++, b++, cout << "+1\n";
        }
    }
    while(d > 1) {
        if(d % 2 == 0) {
            if(c % 2 == 0) c /= 2, d /= 2, cout << "/3\n";
            else b++, c++, cout << "+2\n";
        }
        else {
            c++, d++, cout << "+3\n";
        }
    }
    while(b != 1 || c != 1) {
//    cout << a << b << c << d << endl;
        if(b % 2 == c % 2) {
            if(b % 2 == 1) b++, c++, cout << "+2\n";
            else b /= 2, c /= 2, cout << "/2\n";
        }
        else if(b % 2 == 0) {
            a++, b++; cout << "+1\n";
            b++, c++; cout << "+2\n";
            a /= 2, b /= 2; cout << "/1\n";
        }
        else {
            b++, c++; cout << "+2\n";
            c++, d++; cout << "+3\n";
            c /= 2, d /= 2; cout << "/3\n";
        }
    }

}