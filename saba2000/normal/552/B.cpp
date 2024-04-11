#include <iostream>
using namespace std;
int main ()
{long long int n,an=0,s=9,t=1;
cin>>n;
do
{if (n>=s) {an+=s*t; n-=s;}
else {an+=n*t; n=0;}
t++;
s*=10;}
while (n!=0);
cout<<an<<endl;
return 0;
}