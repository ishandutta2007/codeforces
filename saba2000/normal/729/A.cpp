#include<iostream>
using namespace std;
main()
{string s; int k=0,n;
cin>>n>>s;
for (int i=0; i<s.length()-1; i++)
{if (s[i]=='o') {k=1; continue;}
if (s[i]=='g' && s[i+1]=='o' && k>=1) {i++; if (k==1) {s[i]='*'; s[i-1]='*'; s[i-2]='*';} 
else {s[i]='-'; s[i-1]='-'; }k++;continue;}
k=0;
}
for (int i=0; i<n; i++)
if (s[i]!='-') cout<<s[i];
return 0;

}