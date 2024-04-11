#include <iostream>
using namespace std;
int atas(int a)
{for (int i=a-1; i>1; i--)
if (a%i==0) return 1; 
else if (i==2) return 0;
}
int main ()
{int a,i,j;
cin>>a;
for (i=4; i<=a/2; i++)
{j=a-i;
if (atas(j)==1 && atas(i)==1) break;
}
cout<<i<<" "<<j<<endl;
//system ("pause");
return 0;
}