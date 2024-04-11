#include<bits/stdc++.h>
using namespace std;
int a[1000000];
int b[1000000];
int pa[1000000];
int ok;
int n;
int V=2;
void dfs(int v,int lev)
{
    if (lev!=ok || a[lev]<=1)
    {
        for (int i=1;i<=a[lev];i++)
        {
            pa[V++]=v;
            dfs(V-1,lev+1);
        }
        a[lev]=0;
    }
    else
    {
        for (int i=1;i<a[lev];i++)
        {
            pa[V++]=v;
            dfs(V-1,lev+1);
        }
        a[lev]=1;
    }
}
void PrintTree()
{
    V=2;
    dfs(1,1);
    for (int i=1;i<=n;i++)
        cout<<pa[i]<<' ';
    cout<<endl;
}
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    int h;
    cin>>h;
    for (int i=0;i<=h;i++)
    {
        cin>>a[i],n+=a[i];
        b[i]=a[i];
        if (i>0 && a[i]>1 && a[i-1]>1)
        {
            ok=i;
        }
    }
    if (!ok)cout<<"perfect"<<endl;
    else
    {
        cout<<"ambiguous"<<endl;
        PrintTree();
        ok=0;
        for (int i=0;i<=h;i++)
            a[i]=b[i];
        PrintTree();
    }
}