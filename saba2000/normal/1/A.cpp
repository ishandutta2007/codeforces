#include <iostream>
using namespace std;
int main()
{
long long int m,n,a,b,d;
cin>>n>>m>>a;
if (m%a==0) d=m/a;
else d=m/a+1;
if (n%a==0) b=n/a;
else b=n/a+1;
cout<<b*d;
return 0;
}