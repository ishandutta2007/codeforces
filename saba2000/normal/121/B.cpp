#include <iostream>
#include <string>
using namespace std;
int main ()
{int n,k; string s;
cin>>n>>k>>s;
for (int i=0; i<s.length()-1; i++)
{if (s[i]=='4' && s[i+1]=='4' && s[i+2]=='7' && i%2==0 && k>0) {if (k%2==1) s[i+1]='7'; break;}
if (s[i]=='4' && s[i+1]=='7' && s[i+2]=='7' && i%2==0 && k>0) {if (k%2==1) s[i+1]='4'; break;}
if (s[i]=='4' && s[i+1]=='7' && k>0) if (i%2==0) {s[i]='4'; s[i+1]='4'; k--;}
else {s[i]='7'; s[i+1]='7'; k--; i-=2;}
}
cout<<s<<endl;
return 0;
}