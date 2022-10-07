#include<iostream>
#include<map>
using namespace std;
map<int,int> t;
int n,m,a,b[234567],c[234567];
int ans1,ans2,ans3;
main()
{cin>>n;
for(int i=0; i<n; i++)
{cin>>a;
if (t[a]==0) t[a]=1; else t[a]++;
}
cin>>m;
for (int i=0; i<m; i++)
cin>>b[i];
for (int i=0; i<m; i++)
cin>>c[i];
for (int i=0; i<m; i++)
if (t[b[i]]>ans1 || t[b[i]]==ans1 && t[c[i]]>=ans2) {ans1=t[b[i]]; ans2=t[c[i]]; ans3=i+1;}
cout<<ans3;
}