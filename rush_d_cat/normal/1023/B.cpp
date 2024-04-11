#include <iostream>
using namespace std;
typedef long long LL;

LL n,k;
int main(){
    cin>>n>>k;
    if(n+n-1<k) {
        return !printf("0\n");
    }
    if(n>=k) {
        return !printf("%lld\n", (k-1)/2);
    }
    if(n<k) {
        LL L = k-n, R=n;
        return !printf("%lld\n", (R-L+1)/2);
    }
}