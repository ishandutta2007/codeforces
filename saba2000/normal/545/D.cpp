#include <iostream>
#include <algorithm>
using namespace std;
int main ()
{int a[100009],n,an=0;
long long int ttw=0;
cin>>n;
for (int i=0; i<n; i++)
cin>>a[i];
sort (a,a+n);
for (int i=0; i<n; i++)
{if (ttw<=a[i]) {an++; ttw+=a[i];}
}
cout<<an<<endl;
return 0;
}