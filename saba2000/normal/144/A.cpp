#include <iostream>
using namespace std;
int main ()
{int r,k=0,l=100,m,n,s,an;
cin>>r;
for (int i=0; i<r;i++)
{cin>>s;
if (s>k) {k=s; m=i;}
if (s<=l) {l=s; n=i;}
}an=m+r-n-1; 
if (m>n) an--;
cout<<an<<endl;
return 0;
}