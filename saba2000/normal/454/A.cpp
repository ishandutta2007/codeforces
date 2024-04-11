#include <iostream>
using namespace std;
int main ()
{int n;
cin>>n; int r=n/2,r1=n/2;
for (int i=0; i<n; i++)
{for (int j=0; j<n; j++)
if (j<r || j>r1) cout<<"*"; else cout<<"D";
if (i<n/2){ r1++; r--;}
else{ r++; r1--;}
cout<<endl;
}
//system ("pause");
return 0;
}