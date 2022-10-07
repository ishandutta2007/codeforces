#include<iostream>
#include<cmath>

#include<vector>
#include<algorithm>
using namespace std;
int n,m,k,c[100009],u,x,t[1009],k1[1009],f[1009],ans,uu,kk[1009],p;
vector<int> v[1009];
void go (int a,int b)
{f[a]=1; k1[a]=b; kk[b]++;
for (int i=0; i<v[a].size(); i++)
{t[b]++;
if (f[v[a][i]]==0) go(v[a][i],b);
}}
main()
{cin>>n>>m>>k;
for (int i=0; i<k; i++)
{cin>>c[i];
c[i]--;
}
for (int i=0; i<m; i++)
{cin>>u>>x; u--; x--;
v[u].push_back(x);
v[x].push_back(u);
}
for (int i=0; i<k; i++)
{go(c[i],i+1);
//cout<<kk[i+1]<<" "<<t[i+1]<<endl;
ans+=kk[i+1]*(kk[i+1]-1)/2-t[i+1]/2;uu=max(uu,kk[i+1]);}
for (int i=0; i<n; i++)
{if (k1[i]==0) {go (i,k+1);}}
for (int i=0; i<n; i++)
if (k1[i]==k+1) {ans+=uu; p++;}
//cout<<ans<<endl;
cout<<ans+p*(p-1)/2-t[k+1]/2<<endl;

}