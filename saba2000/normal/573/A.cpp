#include <iostream>
using namespace std;
int n,t,p;
int main ()
{cin>>n;
for (int i=0; i<n; i++)
{cin>>p;
while(p%3==0 || p%2==0) 
{if (p%3==0) p/=3;
if (p%2==0) p/=2;
}
if (i==0) t=p;
else if(p!=t) {cout<<"no"<<endl; return 0;}
}
cout<<"yes"<<endl;
return 0;
}