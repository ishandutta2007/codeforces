#include <iostream>
using namespace std;
int main ()
{
int n,m,s=0,r;
cin>>n>>m;
r=n/2+n%2;
while (r<=n)
{
if (r%m==0) {s=1; break;}
r++;
}
if (s==1) cout<<r;
else cout<<-1;
return 0;
}