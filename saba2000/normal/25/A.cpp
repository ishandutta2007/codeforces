#include <iostream>
using namespace std;
int main ()
{ int n,nu[100],e=0,ei,o=0,oi;
cin>>n;
for (int i=0; i<n; i++)
cin>>nu[i];
for (int i=0; i<n; i++)
if (nu[i]%2==0) {e++; ei=i+1;}
else {o++; oi=i+1;}
if (o==1) cout<<oi<<endl; 
else cout<<ei<<endl;
//system ("pause");
return 0;
}