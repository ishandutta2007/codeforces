#include <iostream>
using namespace std;
int main ()
{int a[20]={0},b[20]={0},r,c,m=0,n=0; char s;
cin>>r>>c;
for (int i=0; i<r; i++)
for (int j=0; j<c; j++)
{cin>>s; if (s=='S') {a[i]=1; b[j]=1;}
}
for (int i=0; i<r; i++)
 if (a[i]==0) m++;
 for (int i=0; i<c; i++)
if (b[i]==0) n++;

cout<<n*r+m*c-n*m<<endl;
return 0;
}