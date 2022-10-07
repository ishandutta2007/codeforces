#include <iostream>
using namespace std;
int main ()
{
char k[100],k1[100],l;
int m,s,s1;
cin>>m>>s;
s1=s;
if (m==1 && s==0) {cout<<0<<" "<<0<<endl; return 0;}
if (s==0 || m*9<s) {cout<<-1<<" "<<-1<<endl; /*system ("pause");*/ return 0;}
if (s-1<(m-1)*9){ k[0]='1'; s--;} else {if (s%9!=0){k[0]=s%9+48; s=s-s%9;} else {k[0]='9'; s=s-9;}}
for (int i=1; i<m; i++)
{if (i<(m-((s+8)/9)))  k[i]='0';
else if (s%9!=0) {l=s%9; k[i]=l+48; s=s-(s%9);}
else {k[i]='9'; s=s-9;}
}
for (int i=0; i<m; i++)
{if (s1>=9) {k1[i]='9';s1=s1-9;}
else {k1[i]=s1%9+48; s1=s1-(s1%9);}
}
for (int i=0; i<m; i++)
cout<<k[i];
cout<<" ";
for (int i=0; i<m; i++)
cout<<k1[i];
cout<<endl;
//system ("pause");
return 0;
}