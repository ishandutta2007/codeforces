# include <iostream>
#include <cmath>
# include <cstdio>
# include <string>
# include <map>
# include <cstdlib>

using namespace std;
int primes[100000];
bool prime(int x)
{
    for (int i=2;i<x;i++)
        if (x%i==0)
            return 0;
    return 1;
}
int main()
{
    int n;
    cin>>n;
    int tot=0;
    for (int i=2;i<=n;i++)
    {
        if (prime(i))
        primes[tot++]=i;
    }
    int j=tot;
    for (int i=0;i<j;i++)
    {
        int cur=primes[i]*primes[i];
        while(cur<=n)
            primes[tot++]=cur,cur*=primes[i];
    }
    cout<<tot<<endl;
    for (int i=0;i<tot;i++)
        cout<<primes[i]<<" ";
}