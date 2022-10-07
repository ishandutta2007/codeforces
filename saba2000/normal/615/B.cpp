#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
long long n,m;
vector<long long> v[100009];
long long a,b,f[100009],t[100009], pm,ans, T=0,z;
main()
{
cin>>n>>m;
for (long long i=0; i<m; i++)
{cin>>a>>b;
v[a].push_back(b);
v[b].push_back(a);
}
for(long long i=1; i<=n; i++)
{t[i]=max(t[i],(long long)1);
for (int j=0;j<v[i].size(); j++)
if (v[i][j]>i)t[v[i][j]]=max(t[v[i][j]],t[i]+1);
}
for (long long i=1; i<=n; i++)
{ans=max(ans,t[i]*(long long)v[i].size());

}
cout<<ans<<endl;

}