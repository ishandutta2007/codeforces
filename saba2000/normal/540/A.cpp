#include <iostream>
#include <cmath>
#include <algorithm>
using namespace std;
int main ()
{int n,s=0;
char a[1000],b[1000];
cin>>n;
for (int i=0; i<n; i++)
cin>>a[i];
for (int i=0; i<n; i++)
cin>>b[i];
for (int i=0; i<n; i++)
s+=min(abs(a[i]-b[i]),10-abs(a[i]-b[i]));
cout<<s<<endl;
//system ("pause");
return 0;
}