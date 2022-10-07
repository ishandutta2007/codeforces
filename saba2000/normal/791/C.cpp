#include<bits/stdc++.h>
using namespace std;
string F(int n)
{string l="";
l+='A'+n/26;
l+='a'+n%26;
return l;}
string s[1000];
main()
{int n,k;
string p;
cin>>n>>k;
for (int i=0; i<k-1; i++)
s[i]=F(i);
int z=k;
for (int j=k-1; j<n; j++)
{cin>>p;

if (p=="NO") s[j]=s[j-k+1];
else {s[j]=F(z); z++;}
}
for (int i=0; i<n; i++)
cout<<s[i]<<" ";
}