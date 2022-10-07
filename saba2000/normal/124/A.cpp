#include <iostream>
using namespace std;
int main ()
{
int n,a,b,c=1,s=1-1;
cin>>n>>a>>b;      
while (c<=n)
{if (c-1<=b & n-c>=a) s++; 
 c++; }
cout<<s;
return 0;
}