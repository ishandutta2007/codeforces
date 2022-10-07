#include <iostream>
using namespace std;
int main ()
{int n,m,a,b,an=0;
cin>>n>>m;
for (a=0; a<=50; a++)
for (b=0; b<=50; b++)
if (a*a+b==n && a+b*b==m) {//cout<<a<<" "<<b<<endl; 
an++;}
cout<<an<<endl;
//system ("pause");
return 0;
}