#include<bits/stdc++.h>
using namespace std;
const int N=1e5+5;
int fa[N];
int arr[N];
int getfa(int v)
{
    if(v==fa[v])
	{
        return fa[v];
    }
    fa[v]=getfa(fa[v]);
    return fa[v];
}
void merge(int u,int v)
{
    int t1=getfa(u);
    int t2=getfa(v);
    if(t1!=t2)
	{
        fa[t2]=t1;
        if(arr[t2])
            arr[t1]=t2;
    }
	else arr[t1]=1;
}
int n,m,cnt;
void init(){for(int i=1;i<=n;i++) fa[i]=i;} 
int main()
{

    cin>>n>>m;
    init();
    cnt=0;
    for(int i=1;i<=m;i++)
	{
        int x,y;
        cin>>x>>y;
        merge(x,y);
    }    
    for(int i=1;i<=n;i++)
	{
        if(fa[i]==i&&!arr[i]) cnt++;
    }
    cout<<cnt<<endl;
}