#include<bits/stdc++.h>
using namespace std;

vector<long long> v[200009];
//set<long long> s[200009];
long long a,b,f[200009],l,k;
void go (long long x, long long p)
{f[x]=1; k++;
l+=v[x].size();
for (long long i=0; i<v[x].size(); i++)
{if (f[v[x][i]]==1) continue;
go(v[x][i],x);}
}

main()
{long long n,m,ans=1;
cin>>n>>m;
for (long long i=0; i<m; i++)
{cin>>a>>b;
v[a].push_back(b);
//s[a].insert(b);
v[b].push_back(a);
//s[b].insert(a);
}
for (long long i=1; i<=n; i++)
{l=0; k=0;
if (f[i]==0) {go(i,-1);
//cout<<l<<" "<<k<<endl;
if (l!=k*(k-1)) ans=0; }
}
if (ans==1) cout<<"YES"<<endl;
else cout<<"NO"<<endl;
}