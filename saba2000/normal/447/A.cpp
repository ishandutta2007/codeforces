#include <iostream>
using namespace std;
int main ()
{int p,n,k[500]={0},an=-1,x;
cin>>p>>n;
for (int i=0; i<n; i++)
{cin>>x;
if (k[x%p]==1 && an==-1) an=i+1; else
k[x%p]=1;
}
cout<<an<<endl;
return 0;
}