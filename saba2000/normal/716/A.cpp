#include<iostream>
using namespace std;
int n,c,b,d,e;
main()
{cin>>n>>c>>e;
d=1;

for (int i=1; i<n; i++)
{cin>>b;
if (b-e<=c) d++;
else d=1;
e=b;
}
cout<<d<<endl;
}