#include <iostream>
using namespace std;
typedef long long LL;
LL n;

LL prime(LL x) {
    for(LL i=2;i*i<=x;i++) {
        if(x%i==0) return i;
    } return x;
}
int main() {
    cin >> n;
    LL ans=0;
    while(n) {
        n -= prime(n); ans ++;
        if(n%2==0) {
            ans += n/2; break;
        }
    } cout<<ans<<endl;
}