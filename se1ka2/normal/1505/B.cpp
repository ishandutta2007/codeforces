#include <iostream>
using namespace std;

int main()
{
    int a;
    cin >> a;
    int b = a;
    while(b >= 10){
        a = b;
        int c = 0;
        while(a){
            c += a % 10;
            a /= 10;
        }
        b = c;
    }
    cout << b << endl;
}