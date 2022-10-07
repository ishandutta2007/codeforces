#include<bits/stdc++.h>
using namespace std;
int a[200009];
int u[200009];
int h[200009];
int f[200009];
int k;
vector<int> v[200009];
void dfs(int x)
{
  //  cout<<x<<endl;
if(u[x]==1) h[x]=1;
f[x]=1;
for(int i=0; i<v[x].size(); i++)
    if(f[v[x][i]]==0) {dfs(v[x][i]); h[x]+=h[v[x][i]];}
   // cout<<x<<" "<<h[x]<<endl;
}
long long ans=0;
void dfs1(int x)
{
    f[x]=2;
    for (int i=0; i<v[x].size(); i++)
        if(f[v[x][i]]!=2) {ans+=min(2*k-h[v[x][i]],h[v[x][i]]); dfs1(v[x][i]);}
}
main()
{
int n;
cin>>n>>k;
for (int i=0; i<2*k; i++)
 {cin>>a[i];
 u[a[i]]=1;}
for (int i=0; i<n-1; i++)
{
    int a,b;
    cin>>a>>b;
    v[a].push_back(b);
    v[b].push_back(a);
}dfs(1); dfs1(1);
cout<<ans<<endl;

}