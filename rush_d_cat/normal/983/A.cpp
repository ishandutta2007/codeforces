#include <iostream>
using namespace std;
typedef long long LL;
int n;
LL p,q,b;
inline LL gcd(LL a, LL b) {
  if (a == 0) return b;
  return gcd(b % a, a);
}

int main() {
    scanf("%d",&n);
    for(int cas=1;cas<=n;cas++) {
        scanf("%lld%lld%lld",&p,&q,&b);
        LL g=gcd(p,q);
        q /= g;
        g = gcd(q, b);
        while (q > 1 && g > 1) {
            g = gcd(q, g);
            q /= g;
        }
        printf("%s\n", (q==1)?"Finite":"Infinite");
    }
}