#include <iostream>
using namespace std;
typedef long long LL;
LL a, b;
int main()
{
    cin >> a >> b;
    for(LL i=1;;i++) {
        if(i%2) {
            a -= i;
        } else {
            b -= i;
        }
        if(a < 0) break;
        if(b < 0) break;
    }
    if(a < 0) printf("Vladik\n");
    else if(b < 0) printf("Valera\n");
}