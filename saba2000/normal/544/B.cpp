#include <iostream>
#include <string>
#include <vector>
using namespace std;
int main ()
{ int n,m,p=0;
cin>>n>>m;
if ((n*n+1)/2<m) cout<<"NO"<<endl; 
else {cout<<"YES"<<endl;
for (int i=0; i<n; i++)
{for (int j=0; j<n; j++)
if (p<m && i%2==j%2) {cout<<"L"; p++;} else cout<<"S";
cout<<endl;
}
}
return 0;
}