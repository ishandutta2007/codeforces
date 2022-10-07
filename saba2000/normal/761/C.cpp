#include<bits/stdc++.h>
using namespace std;
int n,m,d[100],c[100],p[100],ans=100000;
string s;
int main()
{cin>>n>>m;
for (int i=0; i<n; i++)
{cin>>s; d[i]=10000; c[i]=10000; p[i]=10000;
for (int j=0; j<m; j++){
if (s[j]>='0' && s[j]<='9') d[i]=min(d[i],min(j,m-j));
if (s[j]>='a' && s[j]<='z') c[i]=min(c[i],min(j,m-j));
if (s[j]=='#' || s[j]=='*' || s[j]=='&') {p[i]=min(p[i],min(j,m-j)); }} 
}
for (int i=0; i<n; i++)
for (int j=0; j<n; j++)
for (int k=0; k<n; k++)
{if (i==j || j==k || k==i) continue;
ans=min(ans,d[i]+c[j]+p[k]);
}
cout<<ans<<endl;
}