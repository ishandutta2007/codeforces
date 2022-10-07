#include <string>
#include <iostream>
using namespace std;
int main ()
{string k;
int m=0,l=0;
cin>>k;
for (int i=0; i<k.length(); i++)
m=max(k[i]-48,m);
cout<<m<<endl;
for (int i=0; i<m; i++)
{l=0; for (int j=0; j<k.length(); j++)
{if (k[j]=='0' && l!=0) cout<<0;
else if (k[j]!='0') {k[j]--; cout<<1; l=1;}
}
cout<<" ";
}
cout<<endl;
return 0;
}