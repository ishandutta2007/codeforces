#include <iostream>
using namespace std;
int a, b, c, d;
int main() {
    cin >> a >> b >> c >> d;
    int mark1 = max(3*a/10, a - a/250*c);
    int mark2 = max(3*b/10, b - b/250*d);
    printf("%s\n", (mark1==mark2)?"Tie":((mark1>mark2)?"Misha":"Vasya"));
}