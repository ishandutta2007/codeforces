#include <iostream>
#include <string>
using namespace std;
int main ()
{string s; int sum=0,an=1;
cin>>s;
if (s.length()==1) {cout<<0<<endl; return 0;}
for (int i=0; i<s.length(); i++)
sum+=s[i]-48;
while (sum>9)
{int k=0;for (int i=sum; i>0; i/=10) k+=i%10; sum=k; an++;}
cout<<an<<endl;
return 0;
}