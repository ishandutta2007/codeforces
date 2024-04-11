#include <iostream>
using namespace std;
int main ()
{int n,an=0;
cin>>n;
for (int i=0; i<n; i++)
{int x,x1,y,y1;
cin>>x>>y>>x1>>y1;
an+=(y1-y+1)*(x1-x+1);
}
cout<<an<<endl;
return 0;
}