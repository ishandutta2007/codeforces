#include <iostream>
#include <string>
using namespace std;
int main ()
{int a,c,k,an=0,an1=1; string a1="",c1="",b="";
cin>>a>>c;
while (a>0)
{a1=char(a%3+48)+a1;
a=a/3;
}
while (c>0)
{c1=char(c%3+48)+c1;
c=c/3;
}  
while (a1.length()!=c1.length())
if (a1.length()>c1.length()) c1='0'+c1; else a1='0'+a1; 
for (int i=0; i<a1.length(); i++)
{k=(c1[i]-48)%3-(a1[i]-48)%3; if (k<0) k+=3;
b=b+(char)(k+48);
} 
for (int i=b.length()-1; i>=0; i--)
{an+=((b[i]-48)%10)*an1;
an1*=3;
}
cout<<an<<endl;
return 0;
}