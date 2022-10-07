#include <iostream>
#include <string>
using namespace std;
int main ()
{string a,b; int l=0,k=0,r=0;
cin>>a>>b; 
for (int i=a.length()-1; i>=0; i--)
{if (b[i]-a[i]<2 && b[i]-a[i]>0) l++; 
if (b[i]==a[i]) k++;}
if ((b[a.length()-1]-a[a.length()-1]<2 && b[a.length()-1]-a[a.length()-1]>0 && l<2) || k==a.length()) cout<<"No such string"<<endl;
else {int i;
for (i=a.length()-1; a[i]=='z'; i--)
{a[i]='a'; if (b[i]=='a') r++;}
a[i]++; if (a[i]==b[i] && r==a.length()-1-i && r!=0) cout<<"No such string"<<endl; else
cout<<a<<endl;
}
return 0;
}