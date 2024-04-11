#include <iostream>
using namespace std;
int main ()
{
int v1,V,t,d,k=0,r;
cin>>v1>>V>>t>>d; k+=V; r=d;
int g=v1;
for (int i=0; i<t-1; i++)
{k+=g;
while ((g+d)-r*(t-i-2)>V ) d--;
g+=d;}
cout<<endl<<k<<endl;
return 0;
}