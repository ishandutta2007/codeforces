#include <iostream>
using namespace std;
int main ()
{ 
int n;
string s1,s2; 

cin>>n;
if (n%2==0) {cout<<n/2*n<<endl;
for (int i=1; i<=n*n; i++)
{ if (i%2==0 && ((i+n-1)/n)%2==1) cout<<"C";
  if (i%2==1 && ((i+n-1)/n)%2==1) cout<<".";
  if (i%2==0 && ((i+n-1)/n)%2==0) cout<<".";
  if (i%2==1 && ((i+n-1)/n)%2==0) cout<<"C";
  if (i%n==0) cout<<endl;
}
}
if (n%2==1) {cout<<((n/2)*(n/2))+((n/2+1)*(n/2+1))<<endl;
for (int a=1; a<=n*n; a++)
{if (a%2==1) cout<<"C"; else cout<<".";
if (a%n==0) cout<<endl;
}
}
return 0;
}