#include <iostream>
#include <cstdio>
using namespace std;
bool isPrime(int x)
{
    for(int i=2;i*i<=x;i++)
    {
        if(x%i==0) return 0;
    }
    return 1;
}
int main()
{
    int n;cin>>n;
    for(int m=1;;m++)
    {
        if(!isPrime(m*n+1)) {cout << m << endl;return 0;}
    }
}