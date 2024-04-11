#include <iostream> 
#include <string>
using namespace std;
int main ()
{int a[100]={0};
a['A']=1; a['H']=1; a['I']=1; a['M']=1; a['O']=1; a['T']=1; a['U']=1; a['V']=1; a['W']=1; a['X']=1; a['Y']=1;
string s; cin>>s;
for (int i=0; i<s.length(); i++)
if (s[i]!=s[s.length()-i-1] || a[s[i]]==0) {cout<<"NO"<<endl; return 0;}
cout<<"YES"<<endl; return 0;
}