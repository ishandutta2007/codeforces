#include <iostream>
#include <cmath>
using namespace std;
int main(){
    int a,b,c;
    cin >> a >> b >> c;
    long long d = (long long)a*b*c;
    int sqroot = sqrt(d);
    int x = sqroot/a;
    int y = sqroot/b;
    int z = sqroot/c;
    cout << (x+y+z)*4;
}