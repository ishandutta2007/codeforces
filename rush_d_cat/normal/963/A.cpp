#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>
using namespace std;
typedef long long LL;
const LL MOD=1000000009;

const int N=100000+10;
LL n,a,b,k;
char s[N];

LL mpow(LL a, LL x) {
    if (x==0) return 1;
    LL t=mpow(a,x/2);
    if (x%2==0)
        return t*t%MOD;
    return t*t%MOD*a%MOD;
}

int main() {
    cin>>n>>a>>b>>k;
    scanf("%s",s+1);

    LL sum=0;
    LL ret=0;
    for(int i=1;i<=k;i++) {
        if (s[i] == '+') {
            sum += mpow(a, n-i+1) * mpow(b, i-1);
        } else {
            sum -= mpow(a, n-i+1) * mpow(b, i-1);
        }
        sum = (sum % MOD + MOD) % MOD;
    }
    ret=sum;
    LL t = (n+1)/k;
    LL q = mpow(b,k) * mpow(mpow(a,k), MOD-2) % MOD;
    if (q != 1)
        ret = sum * (mpow(q,t) - 1) % MOD * mpow(q-1, MOD-2) %MOD;
    else
        ret = sum * t % MOD;
    cout << ret << endl;


}