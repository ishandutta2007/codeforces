#include <iostream>
#include <cstdio>
#include <algorithm>
using namespace std;
typedef long long ll;
bool isPrime(ll x)
{
    ll t = 2;
    for(t=2;t*t<=x;t++)
    {
        if(x%t==0 && x!=t) return 0;
    }
    return 1;
}
int main()
{
    ll n;cin >> n;
    if(isPrime(n))
    {
        cout << 1 << endl;
        return 0;
    } 
    if(n%2==0)
    {
        cout << 2 << endl;
        return 0;
    }
    if(n%2==1)
    {
        if(isPrime(n-2))
        {
            cout << 2 << endl;
        } else {
            cout << 3 << endl;
        }
        return 0;
    }
}