#include <iostream>
using namespace std;
int main ()
{int n,h=0,j,e=0,dtp=0,k;
cin>>n;
for (int i=0; i<n; i++)
{cin>>j; k=h-j;
if (k>0) e=e+k;
if (k<0) {k=0-k; if (e<k) {dtp+=k-e; e=0;} 
else if (e>=k) e=e-k;} h=j;
//cout<<"e -"<<e<<endl<<"dtp -"<<dtp<<endl;
}
cout<<dtp<<endl;
//system ("pause");
return 0;
}