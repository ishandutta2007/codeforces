#include<string>
#include <iostream>
using namespace std;
int main ()
{
int a[4],an=0;
cin>>a[0]>>a[1]>>a[2]>>a[3];
string s;
cin>>s;
for (int i=0; i<s.length(); i++)
an+=a[s[i]-49];
cout<<an<<endl;
//system ("pause");
return 0;
}