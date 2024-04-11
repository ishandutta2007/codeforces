#include <iostream>
using namespace std;
int main ()
{int n,k;
cin>>n>>k;
if (2*k>n-1) {cout<<-1<<endl; return 0;}
else cout<<n*k<<endl;
for (int i=0; i<n; i++)
for (int j=i+1; j<i+1+k; j++)
printf("%d %d\n",i+1,j%n+1);
return 0;
}