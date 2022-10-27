/*

{p_i},k<=n 
(p_2-p_1)/p_2*p_1+...+[p_k-p_(k-1)]/[p_k*p_(k-1)]+(n-p_k+1)/[p_k*p_(k+1)].
(p_2-p_1)/p_2*p_1 = 1/p_1 - 1/p_2
1/2 - 1/p_k + (n-p_k+1)/[p_k*p_(k+1)]
*/
#include <iostream>
#include <vector>
#include <cstring>
#include <algorithm>
using namespace std;
typedef long long LL;
const int NICO = 10000 + 10;
int T, n;
LL gcd(LL a, LL b)
{
    return b==0?a:gcd(b, a%b);
}
bool isprime(int x)
{
    if(x==2) return 1;
    for(int i=2;i*i<=x;i++)
    {
        if(x%i==0) return 0;
    }
    return 1;
}
int main() 
{
    cin >> T;
    while(T--)
    {
        scanf("%d", &n);
        int tmp = n;
        while(!isprime(tmp))
        {
            tmp --;
        }
        LL x = tmp;
        tmp = n+1;
        while(!isprime(tmp))
        {
            tmp ++;
        }
        LL y = tmp;
        //LL p = x*y - 2*x - 2*(y-n-1);
        LL p = x*y - 2*y + 2*(n-x+1);
        LL q = 2*x*y;
        LL t = gcd(p, q); p/=t, q/=t;
        printf("%lld/%lld\n", p, q);
    }
}