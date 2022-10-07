#include <string>
#include <iostream>
using namespace std;
int main ()
{string a,b,c;
int s[26]={0};
cin>>a>>b>>c;
for (int i=0; i<a.length(); i++)
s[a[i]-65]++;
for (int i=0; i<b.length(); i++)
s[b[i]-65]++;
for (int i=0; i<c.length(); i++)
s[c[i]-65]--;
for (int i=0; i<26; i++)
if (s[i]!=0) {cout<<"NO"<<endl; return 0;}
cout<<"YES"<<endl; 
return 0;
}