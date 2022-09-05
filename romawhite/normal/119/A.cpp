#include <iostream>
#include <string>
#include <vector>
#include <cmath>
#include <algorithm>
#include <set>

using namespace std;
int gcd (int a, int b) {
    if (b == 0)
        return a;
    else
        return gcd (b, a % b);
}
int main()
{
    int a,b,n,k,l,m,i,j;
    cin>>a>>b>>n;
    a=abs(a);
    b=abs(b);
    k=0;
    while (n)
    {     
          k++;
          if (k%2) n-=gcd(a,n);else n-=gcd(b,n);
    }
    cout<<(k+1)%2;   
    return 0;
}