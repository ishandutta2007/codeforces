#include <iostream>
using namespace std;
int a, b;
int f[13];
void init() {
    f[0] = 1;
    for(int i=1;i<=12;i++) {
        f[i] = f[i-1] * i;
    }
}
int main() {
    init();
    cin >> a >> b;
    printf("%d\n", f[min(a, b)]);
}