#include <iostream>
using namespace std;
int main ()
{int d,n,p,an=0;
cin>>d>>n>>p;
for (int i=0; i<n-1; i++)
{if (p!=d) an+=d-p;
cin>>p;
}
cout<<an<<endl;
return 0;
}