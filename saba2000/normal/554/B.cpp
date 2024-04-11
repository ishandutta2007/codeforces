#include <iostream>
#include <string>
using namespace std;
int main ()
{string a[109]; int d,n,an=1;
cin>>n;
for (int i=0; i<n; i++)
cin>>a[i];
for (int i=0; i<n; i++)
{d=0;
for (int j=0; j<n; j++)
if (a[i]==a[j]) d++;
an=max(an,d);
}
cout<<an<<endl;
return 0;
}