#include<bits/stdc++.h>
using namespace std;
pair<int,int> a[1000000];
int b[1000000];
int c[1000000];
int d[1000000];
int main()
{
    int n;
    scanf("%d",&n);
    int mx=0,id=-1;
    set<int> zeros;
    for (int i=1;i<=n;i++)
    {
        scanf("%d",&a[i].first);
        a[i].second=i;
    }
    sort(a+1,a+n+1);
    reverse(a+1,a+n+1);
    int tot=1;
    int curMx = 1;
    zeros.insert(1);
    for (int i=1;i<=n;i++)
    {
        int u = 2*a[i].second;
        int v = 2*a[i].second-1;
        int x = a[i].first;
        if (!zeros.empty())
        {
            int id = *zeros.begin();
            zeros.erase(zeros.begin());
            b[id]=u;
            if (b[id+x]==0)
                b[id+x]=v,curMx=max(curMx,id+x),zeros.erase(id+x);
            else
            {
                c[v]=id+x-1;
            }
            for (int j=tot+1;j<curMx;j++)
                zeros.insert(j);
            tot=curMx;
        }
        else
        {
            if (x==1)
            {
                d[u]=v;
                c[v]=1;
            }
            else
            {
                c[u]=1;
                c[v]=1+x-2;
            }
        }
    }
    vector<pair<int,int> > E;
    for (int i=1;i<tot;i++)
        E.push_back({b[i],b[i+1]});
    for (int i=1;i<=2*n;i++)
    {
        if (c[i]!=0)
        E.push_back({i,b[c[i]]});
    }
    for (int i=1;i<=2*n;i++)
    {
        if (d[i]!=0)E.push_back({i,d[i]});
    }
    for (auto p:E)printf("%d %d\n",p.first,p.second);
}