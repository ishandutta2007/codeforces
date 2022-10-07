#include <string>
#include <iostream>
using namespace std;
int main ()
{string s; int n=0;
cin>>s;
for (int i=0; i<s.length(); i++)
if (s[i]=='H' || s[i]=='Q' || s[i]=='9') n=1;
if (n==0) cout<<"NO"<<endl; else cout<<"YES"<<endl;
//system ("pause");
return 0; 
}