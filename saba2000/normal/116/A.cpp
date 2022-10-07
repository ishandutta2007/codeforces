#include <iostream>
using namespace std;
int main ()
{int n,a,b,c=0,p=0;
cin>>n;
for (int i=0; i<n; i++)
{cin>>a>>b;
p-=a-b;
if (p>c) c=p;
}
cout<<c<<endl;
//system ("pause");
return 0;
}