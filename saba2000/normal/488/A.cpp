#include <iostream>
using namespace std;
int main ()
{
int a,m,l=0;
cin>>a;
int k=0;
while (k==0)
{
a++;
m=abs(a);
while (m>0)
{if (m%10==8)
k=1;
m=m/10;
}
l++;
}
cout<<l<<endl;
return 0;
}