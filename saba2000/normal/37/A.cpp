#include <iostream>
using namespace std;
int main ()
{int a[1500]={0};
int n,r,d,t;
cin>>n;
for (int i=0; i<n; i++)
{cin>>r; a[r]++;
}
d=a[0];
t=0;
for (int i=0; i<1500; i++)
{if (d<a[i]) d=a[i];
if (a[i]>0) t++;
}
cout<<d<<" "<<t<<endl;
//system ("pause");
return 0;
}