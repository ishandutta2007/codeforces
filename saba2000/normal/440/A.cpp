#include <iostream>
using namespace std;
int main ()
{int a[100009]={0},n,k;
cin>>n; for (int i=1; i<n; i++) {cin>>k; a[k]=1;}
for (int i=1; i<=n; i++)
if (a[i]==0) cout<<i;
return 0;
}