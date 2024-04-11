#include <iostream>
using namespace std;

int gcd(int n, int m){
    if(n % m == 0) return m;
    return gcd(m, n % m);
}

int lcm(int n, int m){
    int g = gcd(n, m);
    return n * m / g;
}

int main()
{
    int r, c;
    cin >> r >> c;
    if(c == 1){
        if(r == 1){
            cout << 0 << endl;
            return 0;
        }
        for(int i = 2; i <= r + c; i++) cout << i << endl;
        return 0;
    }
    for(int i = 1; i <= r; i++){
        for(int j = r + 1; j <= r + c; j++) cout << lcm(i, j) << " ";
        cout << endl;
    }
}