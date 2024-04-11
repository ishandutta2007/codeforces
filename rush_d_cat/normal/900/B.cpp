#include <iostream>
using namespace std;
typedef long long LL;
LL a, b, c;


int main() {
    cin >> a >> b >> c; 

    LL mod = 10*b, A=a;
    for (int i=1;i<=10000;i++) {
        A = A * 10 % mod;
        int p = A / b;
        if (p == c) {
            printf("%d\n", i); return 0;
        }
    }
    printf("-1\n");
}