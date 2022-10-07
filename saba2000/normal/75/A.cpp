#include <iostream>
using namespace std;
int main ()
{int a,b,c,a1=0,b1=0,c1=0,m=1;
cin>>a>>b; c=a+b; 
for (int i=a; i>0; i/=10)
{if (i%10!=0) {a1=a1+m*(i%10); m*=10;}} m=1;
for (int i=b; i>0; i/=10)
{if (i%10!=0) {b1=b1+m*(i%10); m*=10;}} m=1;
for (int i=c; i>0; i/=10)
{if (i%10!=0) {c1=c1+m*(i%10); m*=10;}} m=1;
if (a1+b1==c1) cout<<"YES"<<endl;
else cout<<"NO"<<endl;
return 0;
}