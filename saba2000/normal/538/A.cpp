#include <string>
#include <iostream>
using namespace std;
int main ()
{string k,m="CODEFORCES"; int t=0,b=1;
cin>>k;
for (int i=0; i<=10; i++)
{t=0;
for (int j=0; j<i; j++)
if (k[j]!=m[j]) t=1;
for (int j=i; j<10; j++)
if (k[k.length()-10+j]!=m[j]) t=1;
if (t==0) b=0;
}
if (b==0) cout<<"YES"<<endl; else cout<<"NO"<<endl;}