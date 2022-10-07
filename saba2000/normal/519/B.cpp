#include <iostream>
using namespace std;
int main ()
{int n,k;
cin>>n;
int a=0,b=0,c=0;
for (int i=0; i<n; i++)
{cin>>k; a+=k;}
for (int i=1; i<n; i++)
{cin>>k; b+=k;}
for (int i=2; i<n; i++)
{cin>>k; c+=k;}
cout<<a-b<<" "<<b-c<<endl;
return 0;
}