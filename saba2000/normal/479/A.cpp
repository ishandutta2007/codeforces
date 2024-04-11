#include <iostream>
using namespace std;
int main ()
{
int a,b,c;
cin>>a>>b>>c;
int k[8];
k[0]=a+b+c;
k[1]=(a+b)*c;
k[2]=a*(b+c);
k[3]=a*b+c;
k[4]=a+b*c;
k[5]=a*b*c;
k[6]=a*b+c;
int m=k[0];
for (int i=1; i<7; i++)
if (k[i]>m) m=k[i];
cout<<m<<endl;
return 0;
}