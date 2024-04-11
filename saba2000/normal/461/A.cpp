#include <iostream>
#include <algorithm>
using namespace std;
int main ()
{int n,a[300009];
long long sum=0,an=0;
cin>>n;
for (int i=0; i<n; i++){ cin>>a[i];sum+=a[i];}
sort(a,a+n);
an=sum;
for (int i=0; i<n-1; i++)
{an+=sum;
sum-=a[i];
}
cout<<an<<endl;
return 0;
}