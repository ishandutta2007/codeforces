#include<iostream>
#include<map>
using namespace std;
int n,f[1000],ans=0;
main()
{
string k;
cin>>n;
if (n>26) cout<<-1<<endl;
else {cin>>k;
for (int i=0; i<n; i++)
{if (f[k[i]]==0) f[k[i]]=1;
else ans++;
}
cout<<ans<<endl;}
}