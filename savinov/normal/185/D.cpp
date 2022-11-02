#include <iostream>

using namespace std;

long long power (long long a, long long n, long long p)
{

    if (n==0) return 1;
    long long g = power (a,n/2,p);
    if ((n&1)==0) return (g*g)%p; else return (((a*g)%p)*g)%p;
}

long long reverse (long long a, long long p)
{
    return power(a,p-2,p);
}

int main()
{
    int t;
    cin >> t;
    for (int i=0;i<t;i++)
    {
        long long k,l,r,p;
        cin >> k >> l >> r >> p;
        long long gcd = k%2+1;
        long long ans;
        long long nom= ((power(k,power(2,r+1,p-1),p) - 1+p)%p);
        if (k%p==0) nom = p-1;
        long long denom = ((power(k,power(2,l,p-1),p) - 1 + p)%p);
        if (k%p==0) denom = p-1;
        ans = (nom*(reverse(denom,p)))%p;
        if (denom==0) ans = power(2,r-l+1,p);
        ans*=reverse(power(gcd,r-l,p),p);
        ans%=p;

        cout << ans << endl;
    }
    return 0;
}