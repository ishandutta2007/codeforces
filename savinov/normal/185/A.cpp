#include <iostream>

using namespace std;

long long power (long long a, long long n, long long p)
{
    if (n==0) return 1;
    long long g = power (a,n/2,p);
    if ((n&1)==0) return (g*g)%p; else return (((a*g)%p)*g)%p;
}

int main()
{
    long long n;
    cin >> n;
    if (n==0) cout << 1; else
    cout << (power(2,2*n-1,1000000007)+power(2,n-1,1000000007))%1000000007 << endl;
    return 0;
}