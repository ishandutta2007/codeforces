#include <iostream>
#include <string>
using namespace std;
int main ()
{ int l=0,m=1,r=0;
string s;
cin>>s;
if (s[0]-48>4 && s[0]!='9') s[0]=(char)(9-(s[0]-48)+48);
for (int i=1; i<s.length(); i++)
{ 
 if (s[i]>'4')
s[i]=(char)(9-(s[i]-48)+48);
}
cout<<s<<endl;
//system ("pasue");
return 0;
}