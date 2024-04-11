#include <iostream>
#include <string>
using namespace std;
int n,m,a[150];
char p,q;
string s;
int main()
{cin>>n>>m;
cin>>s;
for (int i='a'; i<='z'; i++)
a[i]=i;
for (int i=0; i<m; i++)
{cin>>p>>q;
for (int j='a'; j<='z'; j++)
if (a[j]==p) a[j]=q;
else if (a[j]==q) a[j]=p;
}for (int i=0; i<s.length(); i++)
s[i]=a[s[i]];
cout<<s<<endl;}