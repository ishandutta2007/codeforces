#include <iostream>
using namespace std;
int main ()
{int luor[1000],an=0,d=0;
int n;
cin>>n;
for (int i=0; i<n; i++)
cin>>luor[i];
for (int i=0; i<n; i++)
{if (luor[i]==1) an++; 
if (luor[i]==1 && luor[i+1]!=1) an++;
}
if (an==0 || an==1) cout<<an; else cout<<an-1;
//system ("pause");
return 0;
}