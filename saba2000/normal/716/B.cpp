#include<iostream>
using namespace std;
int a[200],r=1;
main()
{string s;

cin>>s;
if (s.size()<26) {cout<<-1<<endl; return 0;}
for (int i=0; i<s.length(); i++)
{ r=0;
a[s[i]]++;
if (i>=26) a[s[i-26]]--;
if (i>=25) {
for (int j='A';j<='Z'; j++)
if (a[j]>1) {r=1; }
if (r==0)
{for (int j=i; j>=i-25; j--)
if (s[j]=='?') 
for (int e='A'; e<='Z';e++)
if (a[e]==0) {a[e]=1; s[j]=e; break;}

}
if (r==0) break;}
} 
for (int i=0; i<s.length(); i++)
if (s[i]=='?') s[i]='A';
if (r==1)  cout<<-1<<endl;
else cout<<s<<endl;
}