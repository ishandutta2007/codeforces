#include <iostream>
using namespace std;
int usg(int a,int b)
{ for (int i=a; i>0; i--) 
if (a%i==0 && b%i==0) return i;
}
int main ()
{int a,b,n,i,k;
cin>>a>>b>>n;
for (i=0; true; i++)
{if (i%2==0) k=a;
else k=b; 
if (n>usg(k,n)) n-=usg(k,n);
else break;
}
cout<<i%2<<endl;
//system ("pause");
return 0;
}
//95 26 29