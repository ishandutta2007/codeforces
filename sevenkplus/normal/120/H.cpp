#include<cstdio>
#include<cstring>
#include<iostream>
#include<string>
#include<vector>
#include<algorithm>
using namespace std;
#define pb push_back
int n;string a[210];vector<string> b[210],S;vector<int> c[210],d[500000];int fl[500000],gl[210];bool v[210];
void ff(int p,int x,int y,string z)
{
    if(z!="")b[p].pb(z);
    if(y==4)return;
    for(int i=x+1;i<(int)a[p].size();i++)
        ff(p,i,y+1,z+a[p][i]);
}
int gg(int x)
{
    if(v[x])return 0;
    v[x]=1;
    for(vector<int>::iterator i=c[x].begin();i!=c[x].end();i++)
        if(fl[*i]==-1||gg(fl[*i])){fl[*i]=x,gl[x]=*i;return 1;}
    return 0;
}
int main()
{
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    scanf("%d",&n);
    for(int i=0;i<n;i++)cin>>a[i];
    for(int i=0;i<n;i++)
        ff(i,-1,0,""),sort(b[i].begin(),b[i].end()),
        b[i].erase(unique(b[i].begin(),b[i].end()),b[i].end());
    for(int i=0;i<n;i++)
        for(int j=0;j<(int)b[i].size();j++)S.pb(b[i][j]);
    sort(S.begin(),S.end()),S.erase(unique(S.begin(),S.end()),S.end());
    for(int i=0;i<n;i++)
        for(int j=0;j<(int)b[i].size();j++)
            c[i].pb(lower_bound(S.begin(),S.end(),b[i][j])-S.begin()),
            d[c[i].back()].pb(i);
    memset(fl,-1,sizeof fl);
    for(int i=0;i<n;i++)
    {
        memset(v,0,sizeof v);
        if(!gg(i)){puts("-1");return 0;}
    }
    for(int i=0;i<n;i++)cout<<S[gl[i]]<<endl;
    return 0;
}