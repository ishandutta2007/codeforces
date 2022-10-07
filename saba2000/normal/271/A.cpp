#include <iostream>
using namespace std;
int main ()
{int a,i;
cin>>a;
for (i=a+1; i<9013; i++)
if (i%10!=i/10%10 && i/10%10!=i/100%10 && i/100%10!=i/1000 && i%10!=i/1000 && i/10%10!=i/1000 &&  i%10!=i/100%10)
{cout<<i; //system ("pause");
return 0;}
}