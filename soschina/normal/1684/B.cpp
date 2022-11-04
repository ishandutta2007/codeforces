#include <cstdio>
using namespace std;

int t;
long long a, b, c;

int main(){
    scanf("%d", &t);
    while(t--){
        scanf("%lld%lld%lld", &a, &b, &c);
        printf("%lld %lld %lld\n", a + b + c, b + c, c);
    }
    return 0;
}