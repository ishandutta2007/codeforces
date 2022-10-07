#include <iostream>
#include <string>
using namespace std;
int main ()
{
string s; int n=0,m=0;
cin>>s;
for (int i=0; i<s.length(); i++)
if (s[i]=='4') n++; else if (s[i]=='7') m++;
if (m==0 && n==0) cout<<-1<<endl; else
if (m>n) cout<<7<<endl; else cout<<4<<endl;
return 0;
}