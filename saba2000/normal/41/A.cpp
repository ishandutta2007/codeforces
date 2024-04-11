#include <string>
#include <iostream>
using namespace std;
int main ()
{string a,b;
int t,g=0;
cin>>a>>b;
t=a.size();
if (a.size()!=b.size()) {cout<<"NO"<<endl; return 0;}
for (int i=0; i<t; i++)
{if (a[i]!=b[t-i-1]) g=1;
}
if (g==1) cout<<"NO"<<endl; else cout<<"YES"<<endl;
//system ("pause");
}