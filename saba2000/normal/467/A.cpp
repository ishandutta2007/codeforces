#include <iostream>
using namespace std;
int main ()
{int n,p,q,m=0;
cin>>n;
for (int i=0;i<n;i++)
{cin>>p>>q;
if (q-p>=2)m++;
}
cout<<m<<endl;
//system ("pause");
return 0;
}