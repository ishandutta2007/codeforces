#include <iostream>
using namespace std;
int main ()
{long long a,b,t=0,r;
cin>>a>>b;
while (a!=0)
{r=a; a=b; b=r;
t+=a/b;
a=a%b;}
cout<<t;}