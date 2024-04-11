#include <iostream>
using namespace std;
int main ()
{int x,y,a,b,i,t=0,k;
cin>>x>>y>>a>>b; //3 2 5 5
for (i=x; i<=x*y; i++) 
if (i%x==0 && i%y==0) break;  //6
for (int j=a; true; j++) //5
if (j%i==0) {a=j; break;} 
for (int j=b; true; j--)
if (j%i==0) {b=j; break;}
k=(b-a)/i+1;
if (k<0) k=0;
cout<<k<<endl;
//system ("pause");
return 0;

}