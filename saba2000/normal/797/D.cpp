#include<bits/stdc++.h>
using namespace std;
int n;
int v[300009],l[300009],r[300009];
int m[300009],M[300009];
map<int,vector<int> > V;
void dfs(int x,int mi, int ma)
{
    if(x==-1) return;
    //cout<<x<<" "<<mi<<" "<<ma<<endl;
    m[x]=mi;
    M[x]=ma;
    dfs(l[x],min(mi,v[x]),ma);
    dfs(r[x],mi,max(ma,v[x]));
}
int x=0;
int f[100009];
//int F[100009];
map<int,int> S;
map<int,int> F;
main()
{cin>>n;
for(int i=1; i<=n; i++)
{
    int a,b,c;
    cin>>v[i]>>l[i]>>r[i];
    V[v[i]].push_back(i);
    f[l[i]]=1; f[r[i]]=1;
}
int ans=0;
for (int i=1; i<=n; i++)
if(f[i]==0) dfs(i,1e9+1,-1);
for (int i=1; i<=n; i++)
{
   // cout<<m[i]<<" "<<M[i]<<endl;
    if(F[v[i]]!=0) {if(F[v[i]]==1) ans++; continue;}
    int c=0;
    x=i;
    for (int i=0; i<V[v[x]].size(); i++)
        {if(v[x]<m[V[v[x]][i]] && v[x]>M[V[v[x]][i]]) c=1;
        //cout<<v[x]<<" "<<m[V[v[x]][i]]<< " "<<M[V[v[x]][i]]<<endl;
        }
    if(c==0) ans++;
    F[v[x]]=c+1;
}
cout<<ans<<endl;
/*8
6 2 3
3 4 5
1000000000 6 7
1 -1 8
4 -1 -1
5 -1 -1
14 -1 -1
2 -1 -1*/
}