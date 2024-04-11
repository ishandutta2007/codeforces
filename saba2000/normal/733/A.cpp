#include<iostream>
using namespace std;
string a;int i,j=-1,ans;
main()
{cin>>a;a+='A';
for(i;i<a.size();i++)
if(a[i]=='A'||a[i]=='E'||a[i]=='I'||a[i]=='O'||a[i]=='U'||a[i]=='Y'){
ans=max(ans,i-j); j=i;}
cout<<ans<<endl;
}