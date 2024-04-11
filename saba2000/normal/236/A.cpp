#include <iostream>
#include<string>
using namespace std;
int main ()
{
int p[256]={0};
string s;
int j=0;
cin>>s;
for (int i=0; i<s.length(); i++)
if (p[s[i]]==0) {j++; p[s[i]]=1;}
if (j%2==0) cout<<"CHAT WITH HER!"<<endl;
else cout<<"IGNORE HIM!"<<endl;
return 0;
}