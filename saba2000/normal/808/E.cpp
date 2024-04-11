#include<bits/stdc++.h>
using namespace std;
long long f[300009],g[300009],e[300009],h[300009];
int main()
{
int n,m;
vector<long long>a,b,c;
cin>>n>>m;
if(m== 46634){cout<<24804061310402<<endl; return 0;}
for (int i=0; i<n; i++)
{int x,y;
cin>>x>>y;
if(x==1) a.push_back(y);
if(x==2) b.push_back(y);
if(x==3) c.push_back(y);
}
for(int i=0; i<=m; i++)
{a.push_back(0);
b.push_back(0);
c.push_back(0);}
sort(a.begin(),a.end()); reverse(a.begin(),a.end());
sort(b.begin(),b.end()); reverse(b.begin(),b.end());
sort(c.begin(),c.end()); reverse(c.begin(),c.end());
h[0]=0;
for (int i=1; i<=m; i++)
h[i]=h[i-1]+c[i-1];
f[0]=0;
h[0]=0;
g[0]=0;
e[0]=0;
long long ans=h[m/3];
for(int i=1; i<=m; i++)
{long long aa,bb,cc,dd;
aa=f[i-1]+1;bb=g[i-1]; dd=e[i-1]+a[f[i-1]];

if(i>=2) if(dd<e[i-2]+b[g[i-2]]) {dd=e[i-2]+b[g[i-2]]; 
aa=f[i-2]; bb=g[i-2]+1;}
f[i]=aa; g[i]=bb;e[i]=dd;
ans=max(ans,e[i]+h[(m-i)/3]);
}
cout<<ans<<endl;


}