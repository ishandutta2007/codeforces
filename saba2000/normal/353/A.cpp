#include <iostream>
using namespace std;
int main ()
{ int n,d1,d2,s1=0,s2=0,noeo=0;
cin>>n;
for (int i=0; i<n; i++)
{ cin>>d1>>d2;
s1+=d1; s2+=d2;
if (d1%2!=d2%2) noeo++;
}
if ((s1%2!=s2%2) || (s1%2==1 && s2%2==1 && noeo==0)) cout<<-1<<endl;
else if (s1%2==0 && s2%2==0) cout<<0<<endl;
else cout<<1<<endl;
//system ("pause");
return 0;
}