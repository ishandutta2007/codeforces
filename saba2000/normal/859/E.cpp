#include<bits/stdc++.h>
using namespace std;
long long a[100009],b[100009],p[200009],f[200009],r[200009],F[200009],ans=1,flag=0,mod=1000000007;
vector<long long> q[200009];
void dfs(long long x, long long y, long long  z)
{
    f[x]=y;
      if(p[x]==-1) return;
    r[x]=z;
    if(f[p[x]]!=0 && f[p[x]]!=y) {flag=1;return;}
    if(f[p[x]]==y) {int d=(z-r[p[x]]+1);ans=ans*(2-max(2-d,0))%mod; flag=1; return;}
    dfs(p[x],y,z+1);
}
long long e=0;
void dfs1(long long x)
{F[x]=1;
e++;
for (long long i=0; i<q[x].size(); i++)
    if(F[q[x][i]]==0) dfs1(q[x][i]);
}
main()
{
    long long n;
    cin>>n;
    for(long long i=0; i<n; i++)
        {cin>>a[i]>>b[i];
       p[a[i]]=b[i];
       q[b[i]].push_back(a[i]);
       q[a[i]].push_back(b[i]);
       }
       for (long long i=0; i<=2*n; i++)
        if(p[i]==0) p[i]=-1;
    for(long long i=1; i<=2*n; i++)
    {
    e=0; flag=0;
    if(f[i]) continue;
    dfs(i,i,0);
        if(flag==0){ dfs1(i);
        ans=ans*(e)%mod;}
    }
cout<<ans<<endl;
    }