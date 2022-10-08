#include <iostream>
using namespace std;
int main ()
{int n,m,l;
cin>>n>>m; l=n*m/2;
if (n==1 || m==1) cout<<n*m; else
if (n==2 || m==2) cout<<((l-(l-1)%4+3)/2-(int)(l%4==1))*2<<endl; 
else cout<<n*m/2+n*m%2;
return 0;
}