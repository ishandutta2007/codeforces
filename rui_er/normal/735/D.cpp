#include <iostream>
#include <math.h>
using namespace std;

bool prime(int n)
{
    if(n == 1) return false;
    int k = sqrt(n);
    for(int i=2;i<=k;i++) if(!(n%i)) return false;
    return true;
}

int main()
{
    int n;
    cin>>n;
    if(n == 1 || prime(n)) cout<<1<<endl;
    else if(n % 2 == 0) cout<<2<<endl;
    else if(prime(n-2)) cout<<2<<endl;
    else cout<<3<<endl;
    return 0;
}