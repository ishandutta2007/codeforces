#include<bits/stdc++.h>
using namespace std;
int main()
{
string s;
cin>>s;
int f=0,j,i,m=s.length();
for(i=0;i<m;i++)
for(j=0;j<m;j++)
if(s.substr(0,i)+s.substr(j+1)=="CODEFORCES")
{
cout<<"YES";return 0;
}
cout<<"NO";
return 0;
}