#include <iostream>
#include <algorithm>
using namespace std;

long long  a[17] ;
long long  f(long long  n,long long  i)
{
    long long  m = n / a[i] ;
    n = n % a[i] ;
    if(n == 0)
        return m*i ;
    else
        return m*i + min( i+f(a[i]-n,i-1),f(n,i-1) );
}
int main()
{
    long long n , i ;
    a[0] = 0 ;
    for(i = 1 ; i <= 16 ; i++)
        a[i] = a[i-1]*10 + 1 ;
    cin>>n;
    cout<< f(n,16);

}