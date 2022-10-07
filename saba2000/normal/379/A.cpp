#include <iostream>
using namespace std;
int main ()
{
int a,b,r=0,k;
cin>>a>>b;
while (a>0)
{
r++;
a--;
if (r%b==0)
a++;
}
cout<<r;
return 0;
}