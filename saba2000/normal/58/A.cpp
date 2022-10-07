#include <iostream>
#include <string>
using namespace std;
int main ()
{string s;
char ch[5]={'h','e','l','l','o'};
int m=0,k=0;
cin>>s;
for (int i=0; i<s.length(); i++)
{
if (s[i]==ch[k]) {m++; k++;}

}
if (m==5)
cout<<"YES"<<endl;
else cout<<"NO"<<endl;
//system ("pause");
return 0;
}