#include <iostream>
using namespace std;
int main ()
{int c[26]={0},m=0;
char a,b;
cin>>a;
for (int i=0; a!='}'; i++ )
{cin>>a;
if (a>96 && a<123 && c[a-97]==0) {c[a-97]=1; m++;}
}
cout<<m<<endl;
//system ("pause");
return 0;
}