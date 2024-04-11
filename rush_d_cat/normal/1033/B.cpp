#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
const int N = 200000 + 10;
typedef long long LL;
int t; LL a,b;
bool isprime(LL x) {
    if(x==2) return 1;
    if(x==3) return 1;
    for(LL i=2;i*i<=x;i++) {
        if(x%i==0) return 0;
    }
    return 1;
}
int main() {
    cin >> t;
    while(t--) {
        cin >> a >> b;
        if (a-b!=1) {
            printf("NO\n"); continue;
        }
        printf("%s\n", isprime(a+b)?"YES":"NO");
    }
}