#include<bits/stdc++.h>
using namespace std;
vector<int> v[300009],k[300009];
int f[300009],d[300009],F[300009],l[300009];
int w=-1,s=0,xx=0;
int n,m;
void dfs(int x)
{F[x]=1;
int t=0;
for (int i=0; i<v[x].size(); i++)
{
if(F[v[x][i]]) continue;
dfs(v[x][i]);
if(l[v[x][i]]==1) {t++; xx++;f[k[x][i]]=1;}
}
if(t%2==d[x]) l[x]=0;
else l[x]=1;
}
main()
{cin>>n>>m;
for (int i=1; i<=n; i++){
cin>>d[i];
s+=d[i];
if(d[i]==-1) w=i;
}
if(w==-1 && s%2==1) {cout<<-1<<endl; return 0;}
if(w==-1) w=1;
for (int i=0; i<m; i++)
{
    int a,b;
    cin>>a>>b;
    v[a].push_back(b);
    v[b].push_back(a);
    k[a].push_back(i+1);
    k[b].push_back(i+1);
}
dfs(w);
cout<<xx<<endl;
for (int i=1; i<=m; i++)
if(f[i]) cout<<i<<endl;
}