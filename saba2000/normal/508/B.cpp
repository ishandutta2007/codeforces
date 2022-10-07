#include<iostream>
#include <string>
using namespace std;
int main ()
{
string s;
int a=0,k;
char p;
cin>>s;
k=s.length()-2;
for (int i=0; i<k; i++ )
if (s[i]-48<s[k+1]-48 && (s[i]-48)%2==0 ) {p=s[i]; s[i]=s[k+1]; s[k+1]=p;  a=1; break;}
if (a==0){
for (int i=k; i>=0; i-- )
{
if ((s[i]-48)%2==0) {p=s[i]; s[i]=s[k+1]; s[k+1]=p;  a=1; break; } } }
if (a==0) cout<<-1<<endl; else
 cout<<s<<endl;
//system ("pause");
return 0;
}