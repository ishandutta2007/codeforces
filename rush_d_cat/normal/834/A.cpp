#include <iostream>
using namespace std;
char a, b;
int x, y, n;
int main() {
    cin >> a >> b;
    cin >> n;
    if(a == '^') x = 1;
    if(a == '>') x = 2;
    if(a == 'v') x = 3;
    if(a == '<') x = 4;
    
    if(b == '^') y = 1;
    if(b == '>') y = 2;
    if(b == 'v') y = 3;
    if(b == '<') y = 4;    

    int d = y - x;
    if(d < 0) d += 4;
    if(n % 4 == d && n % 4 == (4 - d) % 4) printf("undefined\n");
    else if(n % 4 == d) printf("cw\n");
    else if(n % 4 == (4 - d) % 4) printf("ccw\n");
}