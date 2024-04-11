#include <iostream>
using namespace std;
int main ()
{int a[100010]; int n,i=0,j,m=0;
cin>>n; j=n-1;
for (int i=0; i<n; i++)
cin>>a[i];
while (i<j-1)
{m=min(a[i],a[j]);
a[i]-=m; a[j]-=m; if (a[i]==0 && i!=j-1) i++; if (a[j]==0 && i!=j-1) j--;}
cout<<i+1<<" "<<n-i-1<<endl;
return 0;
}