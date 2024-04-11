#include <iostream>
using namespace std;
int main ()
{int an=-1; int n,s,x,y;
cin>>n>>s;
for (int  i=0; i<n; i++)
{cin>>x>>y;
if (x*100+y<=s*100 && (100-y)%100>an) an=(100-y)%100;
}
cout<<an<<endl;
}