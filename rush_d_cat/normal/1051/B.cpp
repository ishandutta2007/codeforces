#include <iostream>
using namespace std;
typedef long long LL;
LL x, y;
int main() {
    cin>>x>>y;
    printf("YES\n");
    for(LL i=x;i<=y;i+=2) {
        printf("%lld %lld\n", i,i+1);
    }
}