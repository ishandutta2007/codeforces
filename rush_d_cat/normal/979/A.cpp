#include <iostream>
using namespace std;
typedef long long LL;
LL n;
int main() {
    cin>>n; n++;
    if(n==1) {
        printf("0\n");
        return 0;
    }
    if (n%2==0) {
        printf("%lld\n", n/2);
    } else {
        printf("%lld\n", n);
    }
}