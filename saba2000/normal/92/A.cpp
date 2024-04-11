#include <iostream>
using namespace std;
int main ()
{int n,rch,b;
cin>>n>>rch;
b=rch;
for (int j=0; j<=b; j++)
for (int i=0; i<n; i++)
{rch-=i+1; 
if (rch<0) {
cout<<rch+i+1<<endl;
//system ("pause");
return 0;}}}